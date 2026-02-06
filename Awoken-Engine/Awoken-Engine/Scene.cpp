#include "Scene.h"
#include <glad/glad.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Camera.h"
#include "Object.h"
#include "DirectionalLight.h"

Scene::Scene()
{
	ambientLight = vec3(0.2f);
	directionalLight = nullptr;
}

void Scene::Awake()
{
    if (camera == nullptr)
    {
        camera = new Camera();
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

Camera* Scene::getCamera()
{
    return camera;
}
