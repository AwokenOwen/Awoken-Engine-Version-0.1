#include "WorldManager.h"

int WorldManager::Start()
{
	return 0;
}

void WorldManager::Stop()
{
}

WorldManager& WorldManager::getInstance()
{
	static WorldManager single;
	return single;
}

int WorldManager::loadScene(string name)
{
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

WorldManager::WorldManager()
{
}
