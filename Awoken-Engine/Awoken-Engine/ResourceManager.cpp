#include "ResourceManager.h"
#include "WorldManager.h"
#include "Scene.h"

int ResourceManager::Initialize()
{
	return 0;
}

void ResourceManager::Terminate()
{
	return;
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

ResourceManager::ResourceManager()
{
}
