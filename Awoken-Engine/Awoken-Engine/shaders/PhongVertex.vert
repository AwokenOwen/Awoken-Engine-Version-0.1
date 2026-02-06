#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;
  
out vec3 FragPos;
out vec3 Normal;
out vec2 TexCoord;

uniform mat4 modelViewProjection;
uniform mat4 modelView;

void main()
{
    gl_Position =  modelViewProjection * vec4(aPos, 1.0);
    FragPos = vec3(modelView * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(modelView))) * aNormal;
    TexCoord = aTexCoords;
}