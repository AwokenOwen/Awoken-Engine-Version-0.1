#include "Scene.h"
#include <glad/glad.h>
#include <iostream>
#include "Camera.h"

#include "Object.h"

Scene::Scene()
{
    const char* vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "uniform mat4 model;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = model * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

    const char* fragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(0.0f, 0.5f, 0.0f, 1.0f);\n"
        "}\0";

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

void Scene::Awake()
{
    if (camera == nullptr)
    {
        camera = new Camera();
        camera->SetLocalPosition(vec3(0.0f, 1.0f, -1.0f));
        std::cout << "Camera Created" << std::endl;
    }
	for (int i = 0; i < inScene.size(); i++)
	{
		if (inScene[i]->getActiveState())
		{
			inScene[i]->Awake();
		}
	}
}

void Scene::Start()
{
	for (int i = 0; i < inScene.size(); i++)
	{
		if (inScene[i]->getActiveState())
		{
			inScene[i]->Start();
		}
	}
}

void Scene::Update()
{
	for (int i = 0; i < inScene.size(); i++)
	{
		if (inScene[i]->getActiveState())
		{
			inScene[i]->Update();
		}
	}
}

void Scene::LateUpdate()
{
	for (int i = 0; i < inScene.size(); i++)
	{
		if (inScene[i]->getActiveState())
		{
			inScene[i]->LateUpdate();
		}
	}

	for (int i = 0; i < toBeAdded.size(); i++)
	{
		inScene.push_back(toBeAdded[i]);
	}
	toBeAdded.clear();

	for (int i = 0; i < toBeDeleted.size(); i++)
	{
		toBeDeleted[i]->Destroy();
	}
	toBeDeleted.clear();
}

string Scene::getName()
{
	return name;
}

void Scene::Instantiate(Object* obj)
{
	toBeAdded.push_back(obj);
}

unsigned int Scene::getShaderProgram()
{
	return shaderProgram;
}

Camera* Scene::getCamera()
{
    return camera;
}
