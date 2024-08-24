#include "ResourceManager.h"
#include "WorldManager.h"
#include "Scene.h"

int ResourceManager::Start()
{
	return 0;
}

void ResourceManager::Stop()
{
	saveGame();
}

ResourceManager& ResourceManager::getInstance()
{
	static ResourceManager single;
	return single;
}

int ResourceManager::loadScene(string name)
{
	return 0;
}

int ResourceManager::saveGame()
{
	return 0;
}

ResourceManager::ResourceManager()
{
}
