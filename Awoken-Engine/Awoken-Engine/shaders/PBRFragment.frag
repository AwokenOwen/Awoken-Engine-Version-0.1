#version 330 core
out vec4 FragColor;
in vec2 TexCoords;
in vec3 WorldPos;
in vec3 Normal;

// material parameters
uniform sampler2D albedoMap;
uniform sampler2D normalMap;
uniform sampler2D metallicMap;
uniform sampler2D roughnessMap;
uniform sampler2D aoMap;
uniform sampler2D emissionMap;

// lights
uniform vec3 dirLightDir;
uniform vec3 dirLightColor;

uniform vec3 lightPositions[4];
uniform vec3 lightColors[4];

uniform vec3 camPos;

const float PI = 3.14159265359;
  
float DistributionGGX(vec3 N, vec3 H, float roughness);
float GeometrySchlickGGX(float NdotV, float roughness);
float GeometrySmith(vec3 N, vec3 V, vec3 L, float roughness);
vec3 fresnelSchlick(float cosTheta, vec3 F0);
vec3 getNormalFromMap();
vec3 CalcDirectionalLight(vec3 albedo, float metallic, float roughness, vec3 N, vec3 V, vec3 L, vec3 F0);
vec3 CalcOtherLight(vec3 albedo, float metallic, float roughness, vec3 N, vec3 V, vec3 L, vec3 F0, vec3 lightColor);

void main() {
    vec3 albedo     = pow(texture2D(albedoMap, TexCoords).rgb, vec3(2.2));
    float metallic  = texture2D(metallicMap, TexCoords).r;
    float roughness = clamp(texture2D(roughnessMap, TexCoords).r, 0.1, 1.0);
    float ao        = texture2D(aoMap, TexCoords).r;
    vec3 emission   = texture2D(emissionMap, TexCoords).rgb;

    vec3 N = normalize(Normal);
    vec3 V = normalize(camPos - WorldPos);

    vec3 F0 = vec3(0.04); 
    F0 = mix(F0, albedo, metallic);

    // reflectance equation
    vec3 Lo = vec3(0.0);

    //Directional Light
    Lo += CalcDirectionalLight(albedo, metallic, roughness, N, V, dirLightDir, F0);
    
    //All other lights
    for(int i = 0; i < 4; ++i) 
    {
        Lo += CalcOtherLight(albedo, metallic, roughness, N, V, lightPositions[i], F0, lightColors[i]);
    }   
  
    vec3 ambient = vec3(0.03) * albedo * ao;
    vec3 color = Lo + ambient;

    color = color / (color + vec3(1.0));
    color = pow(color, vec3(1.0/2.2));  
   
    FragColor = vec4(color, 1.0);
} 

float DistributionGGX(vec3 N, vec3 H, float roughness){
    float a      = roughness*roughness;
    float a2     = a*a;
    float NdotH  = max(dot(N, H), 0.0);
    float NdotH2 = NdotH*NdotH;
	
    float num   = a2;
    float denom = (NdotH2 * (a2 - 1.0) + 1.0);
    denom = PI * denom * denom;
	
    return num / denom;
}

float GeometrySchlickGGX(float NdotV, float roughness){
    float r = (roughness + 1.0);
    float k = (r*r) / 8.0;

    float num   = NdotV;
    float denom = NdotV * (1.0 - k) + k;
	
    return num / denom;
}
float GeometrySmith(vec3 N, vec3 V, vec3 L, float roughness){
    float NdotV = max(dot(N, V), 0.0);
    float NdotL = max(dot(N, L), 0.0);
    float ggx2  = GeometrySchlickGGX(NdotV, roughness);
    float ggx1  = GeometrySchlickGGX(NdotL, roughness);
	
    return ggx1 * ggx2;
}
vec3 fresnelSchlick(float cosTheta, vec3 F0){
    return F0 + (1.0 - F0) * pow(clamp(1.0 - cosTheta, 0.0, 1.0), 5.0);
}
vec3 getNormalFromMap(){
    vec3 tangentNormal = texture2D(normalMap, TexCoords).xyz * 2.0 - 1.0;

    vec3 Q1  = dFdx(WorldPos);
    vec3 Q2  = dFdy(WorldPos);
    vec2 st1 = dFdx(TexCoords);
    vec2 st2 = dFdy(TexCoords);

    vec3 N   = normalize(Normal);
    vec3 T  = normalize(Q1*st2.t - Q2*st1.t);
    vec3 B  = -normalize(cross(N, T));
    mat3 TBN = mat3(T, B, N);

    return normalize(TBN * tangentNormal);
}

vec3 CalcDirectionalLight(vec3 albedo, float metallic, float roughness, vec3 N, vec3 V, vec3 L, vec3 F0){
    vec3 H = normalize(V + L);
    float attenuation = 1.0;
    vec3 radiance     = dirLightColor * attenuation;
    
    // cook-torrance brdf
    float NDF = DistributionGGX(N, H, roughness);        
    float G   = GeometrySmith(N, V, L, roughness);      
    vec3 F    = fresnelSchlick(max(dot(H, V), 0.0), F0);       
    
    vec3 kS = F;
    vec3 kD = vec3(1.0) - kS;
    kD *= 1.0 - metallic;	  
    
    vec3 numerator    = NDF * G * F;
    float denominator = 4.0 * max(dot(N, V), 0.0) * max(dot(N, L), 0.0) + 0.0001;
    vec3 specular     = numerator / denominator;  
        
    // add to outgoing radiance Lo
    float NdotL = max(dot(N, L), 0.0);                
    return (kD * albedo / PI + specular) * radiance * NdotL; 
    //return (numerator);
}

vec3 CalcOtherLight(vec3 albedo, float metallic, float roughness, vec3 N, vec3 V, vec3 lightPosition, vec3 F0, vec3 lightColor)
{
    // calculate per-light radiance
    vec3 L = normalize(lightPosition - WorldPos);
    vec3 H = normalize(V + L);
    float distance    = length(lightPosition - WorldPos);
    float attenuation = 1.0 / (distance * distance);
    vec3 radiance     = lightColor * attenuation;        
    
    // cook-torrance brdf
    float NDF = DistributionGGX(N, H, roughness);        
    float G   = GeometrySmith(N, V, L, roughness);      
    vec3 F    = fresnelSchlick(max(dot(H, V), 0.0), F0);       
    
    vec3 kS = F;
    vec3 kD = vec3(1.0) - kS;
    kD *= 1.0 - metallic;	  
    
    vec3 numerator    = NDF * G * F;
    float denominator = 4.0 * max(dot(N, V), 0.0) * max(dot(N, L), 0.0) + 0.0001;
    vec3 specular     = numerator / denominator;  
        
    // add to outgoing radiance Lo
    float NdotL = max(dot(N, L), 0.0);                
    return (kD * albedo / PI + specular) * radiance * NdotL; 
}