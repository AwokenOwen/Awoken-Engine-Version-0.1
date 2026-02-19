#include "Material.h"
#include "glad/glad.h"
#include "ResourceManager.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


Material::Material()
{
    setShaderProgram("assets/defaultAssets/default.vert", "assets/defaultAssets/default.frag");
    type = MaterialType::DEFAULT_LIT;
    twoSided = false;
}

Material::Material(const char* vertexShaderPath, const char* fragmentShaderPath)
{
    setShaderProgram(vertexShaderPath, fragmentShaderPath);
    type = MaterialType::DEFAULT_LIT;
}

unsigned int Material::getShaderProgram()
{
    return shaderProgram;
}

void Material::loadTextures() 
{
    int skyboxLoc = glGetUniformLocation(shaderProgram, "skybox");
    glUniform1i(skyboxLoc, 0);

    switch (type)
    {
    case DEFAULT_LIT:
        loadDefaultLitTextures();
        break;
    case CUBEMAP:
        glBindTexture(GL_TEXTURE_CUBE_MAP, skyboxTexture);
        break;
    default:
        loadDefaultLitTextures();
        break;
    }

    
}

void Material::setTexture(const char* path)
{
    textures.push_back(Resource.loadImage(path));
}

void Material::setTexture(const char* path, int index)
{
    textures[index] = Resource.loadImage(path);
}

void Material::setCubeMapTexture(vector<const char*> paths)
{
    skyboxTexture = Resource.loadCubeMap(paths);
}

void Material::loadDefaultLitTextures()
{
    for (int i = 0; i < textures.size(); i++)
    {
        int loc = glGetUniformLocation(shaderProgram, string("texture[" + to_string(i) + "]").c_str());
        glUniform1i(loc, i);

        glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_2D, textures[i]);
    }

    glBindTexture(GL_TEXTURE_CUBE_MAP, skyboxTexture);
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
