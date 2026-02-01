#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;
  
out vec4 vertexColor; // specify a color output to the fragment shader
out vec2 TexCoord;

uniform mat4 model;

void main()
{
    gl_Position =  model * vec4(aPos, 1.0); // see how we directly give a vec3 to vec4's constructor
    vertexColor = vec4(aTexCoords, 0.0, 1.0); // set the output variable to a dark-red color
    TexCoord = aTexCoords;
}