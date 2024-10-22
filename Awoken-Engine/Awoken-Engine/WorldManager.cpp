#include "WorldManager.h"

int WorldManager::Initialize()
{
	return 0;
}

void WorldManager::Terminate()
{
}

WorldManager& WorldManager::getInstance()
{
	static WorldManager single;
	return single;
}

int WorldManager::loadScene(string name)
{
	//do stuff (set active Scene to the scene with name)
	//load all objects in the scene
	//this is the first frame technically
	activeScene->Awake();
	return 0;
}

Scene* WorldManager::getActiveScene()
{
	return activeScene;
}

void WorldManager::setBaseScene(string name)
{
	nameOfBaseScene = name;
}

string WorldManager::getBaseScene()
{
	return nameOfBaseScene;
}

void WorldManager::Instantiate(Object* obj)
{
	activeScene->Instantiate(obj);
}

void WorldManager::Awake()
{
	activeScene->Awake();
}

void WorldManager::Update()
{
	activeScene->Update();
}

void WorldManager::LateUpdate()
{
	activeScene->LateUpdate();
}

WorldManager::WorldManager()
{

}
