#version 330 core
uniform vec3 dirLightDir;
uniform vec3 dirLightPow;
uniform vec3 dirLightColor;

uniform vec3 lightPositions[4];
uniform vec3 lightColors[4];

uniform sampler2D albedoMap;
uniform sampler2D normalMap;
uniform sampler2D metallicMap;
uniform sampler2D roughnessMap;
uniform sampler2D aoMap;
uniform sampler2D emissionMap;

out vec4 FragColor;
  
in vec3 Normal;
in vec2 TexCoord;
in vec3 FragPos;

uniform vec3 camPos;

vec3 CalcDirLight(vec3 normal, vec3 viewDir);

void main()
{
    // properties
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(camPos - FragPos);

    //phase 0: ambient light
    vec3 result = 0.2 * vec3(texture(albedoMap, TexCoord));

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
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);

    // combine results
    vec3 diffuse  = dirLightColor * diff * vec3(texture(albedoMap, TexCoord));
    vec3 specular = dirLightColor * spec;
    return diffuse + specular;
}  