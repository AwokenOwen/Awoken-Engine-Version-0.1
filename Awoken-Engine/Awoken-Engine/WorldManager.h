#pragma once
#include <string>

#include "Scene.h"

using namespace std;

#define World WorldManager::getInstance()

class WorldManager
{
public:
	//Start the World Manager
	int Initialize();

	//Stop the World Manager
	void Terminate();

	//Singleton Get Function
	static WorldManager& getInstance();

	//Load a Scene
	int loadScene(string name);

	//Get the Current Running Scene
	Scene* getActiveScene();

	//Set the default scene on build
	void setBaseScene(string name);

	//gets base scene name
	string getBaseScene();

	//Instantiate an Object into the active Scene
	void Instantiate(Object* obj);

	//called once at the start of a scene
	virtual void Awake();
	//called every frame
	virtual void Update();
	//called every frame after update
	virtual void LateUpdate();

private:
	WorldManager();

	Scene* activeScene;

	string nameOfBaseScene = "Main";
};