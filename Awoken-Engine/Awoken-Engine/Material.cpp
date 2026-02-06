#include "Material.h"
#include "glad/glad.h"
#include "ResourceManager.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


Material::Material()
{
    loadBaseTextures();
    setShaderProgram("shaders/PBRVertex.vert", "shaders/PBRFragment.frag");
}

Material::Material(const char* vertexShaderPath, const char* fragmentShaderPath)
{
    loadBaseTextures();
    setShaderProgram(vertexShaderPath, fragmentShaderPath);
}

unsigned int Material::getShaderProgram()
{
    return shaderProgram;
}

void Material::loadTextures() 
{
    int albedoLoc = glGetUniformLocation(shaderProgram, "albedoMap");
    glUniform1i(albedoLoc, 0);
    int normalLoc = glGetUniformLocation(shaderProgram, "normalMap");
    glUniform1i(normalLoc, 1);
    int metallicLoc = glGetUniformLocation(shaderProgram, "metallicMap");
    glUniform1i(metallicLoc, 2);
    int roughnessLoc = glGetUniformLocation(shaderProgram, "roughnessMap");
    glUniform1i(roughnessLoc, 3);
    int ambientOcclusionLoc = glGetUniformLocation(shaderProgram, "aoMap");
    glUniform1i(ambientOcclusionLoc, 4);
    int emissionLoc = glGetUniformLocation(shaderProgram, "emissionMap");
    glUniform1i(emissionLoc, 5);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, albedoTexture);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, normalTexture);

    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, metallicTexture);

    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, roughnessTexture);

    glActiveTexture(GL_TEXTURE4);
    glBindTexture(GL_TEXTURE_2D, ambientOcclusionTexture);

    glActiveTexture(GL_TEXTURE5);
    glBindTexture(GL_TEXTURE_2D, emissionTexture);


    for (int i = 0; i < extraTextures.size(); i++)
    {
        glActiveTexture(GL_TEXTURE6 + i);
        glBindTexture(GL_TEXTURE_2D, extraTextures[i]);
    }
}

void Material::setAlbedoTexture(const char* path, int type)
{
    switch (type)
    {
    case 0:
        albedoTexture = Resource.loadJPG(path);
        break;
    default:
        albedoTexture = Resource.loadPNG(path);
        break;
    }
}

void Material::setMetallicTexture(const char* path, int type)
{
    switch (type)
    {
    case 0:
        metallicTexture = Resource.loadJPG(path);
        break;
    default:
        metallicTexture = Resource.loadPNG(path);
        break;
    }
}

void Material::setNormalTexture(const char* path, int type)
{
    switch (type)
    {
    case 0:
        normalTexture = Resource.loadJPG(path);
        break;
    default:
        normalTexture = Resource.loadPNG(path);
        break;
    }
}

void Material::setRoughnessTexture(const char* path, int type)
{
    switch (type)
    {
    case 0:
        roughnessTexture = Resource.loadJPG(path);
        break;
    default:
        roughnessTexture = Resource.loadPNG(path);
        break;
    }
}

void Material::setAmbientOcclusionTexture(const char* path, int type)
{
    switch (type)
    {
    case 0:
        ambientOcclusionTexture = Resource.loadJPG(path);
        break;
    default:
        ambientOcclusionTexture = Resource.loadPNG(path);
        break;
    }
}

void Material::setEmissionTexture(const char* path, int type)
{
    switch (type)
    {
    case 0:
        emissionTexture = Resource.loadJPG(path);
        break;
    default:
        emissionTexture = Resource.loadPNG(path);
        break;
    }
}

void Material::loadBaseTextures()
{
    albedoTexture = Resource.defaultTexture_white;
    metallicTexture = Resource.defaultTexture_black;
    normalTexture = Resource.defaultTexture_normal;
    roughnessTexture = Resource.defaultTexture_halfWhite;
    emissionTexture = Resource.defaultTexture_black;
    ambientOcclusionTexture = Resource.defaultTexture_white;  
}

void Material::setShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath)
{
    // 1. retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // open files
        vShaderFile.open(vertexShaderPath);
        fShaderFile.open(fragmentShaderPath);
        std::stringstream vShaderStream, fShaderStream;
        // read file’s buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const char* vertexShaderSource = vertexCode.c_str();
    const char* fragmentShaderSource = fragmentCode.c_str();

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::COMILATION_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}
