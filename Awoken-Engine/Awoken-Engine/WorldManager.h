#pragma once
#include <string>

#include "Scene.h"

using namespace std;

#define World WorldManager::getInstance()

class WorldManager
{
public:
	int Start();

	void Stop();

	static WorldManager& getInstance();

	int loadScene(string name);

	Scene* getActiveScene();

	void setBaseScene(string name);

private:
	WorldManager();

	Scene* activeScene;

	string nameOfBaseScene;
};