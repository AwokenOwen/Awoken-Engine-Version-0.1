#include "Scene.h"

#include <iostream>

#include "Object.h"

Scene::Scene()
{
}

void Scene::Awake()
{
	for (int i = 0; i < inScene.size(); i++)
	{
		if (inScene[i]->getActiveState())
		{
			inScene[i]->Awake();
		}
	}
}

void Scene::OnEnable()
{
	for (int i = 0; i < inScene.size(); i++)
	{
		if (inScene[i]->getActiveState())
		{
			inScene[i]->OnEnable();
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

void Scene::OnDisable()
{
	for (int i = 0; i < inScene.size(); i++)
	{
		if (inScene[i]->getActiveState())
		{
			inScene[i]->OnDisable();
		}
	}
}

string Scene::getName()
{
	return name;
}

void Scene::Instantiate(Object* obj)
{
	toBeAdded.push_back(obj);
}
