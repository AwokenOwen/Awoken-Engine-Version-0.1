#version 330 core
uniform vec3 dirLightDir;
uniform vec3 dirLightColor;

struct PointLight {    
    vec3 position;
    
    float constant;
    float linear;
    float quadratic;  

    vec3 color;
};  
#define NR_POINT_LIGHTS 4  
uniform PointLight pointLights[NR_POINT_LIGHTS];

struct Material
{
    sampler2D baseColorTexture;
    sampler2D metallicTexture;
    sampler2D roughnessTexture;
    sampler2D ambientOcclusionTexture;
    sampler2D opacityTexture; // For later
};
uniform Material material;

out vec4 FragColor;
  
in vec3 Normal;
in vec2 TexCoord;
in vec3 FragPos;

uniform vec3 camPos;

vec3 CalcDirLight( vec3 normal, vec3 viewDir); 
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);  

void main()
{
    // properties
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(camPos - FragPos);

    //phase 0: ambient light
    vec3 result = 0.2 * vec3(texture(material.baseColorTexture, TexCoord));

    // phase 1: Directional lighting
    result += CalcDirLight(norm, viewDir);  

    FragColor = vec4(result, 1.0);
} 

vec3 CalcDirLight(vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(dirLightDir);

    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);

    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32) * 0.1;

    // combine results
    vec3 diffuse  = dirLightColor * diff * vec3(texture(material.baseColorTexture, TexCoord));
    vec3 specular = dirLightColor * spec;
    return diffuse + specular;
}  