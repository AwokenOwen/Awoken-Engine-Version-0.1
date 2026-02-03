#pragma once
#include <fstream>
#include <string>

using namespace std;

#define Resource ResourceManager::getInstance()

class ResourceManager
{
public:
	//Start the Resource Manager make folders and files nessesary for running the game if not made already
	int Initialize();

	//close files and stop the Resource Manager
	void Terminate();

	//Singleton get function
	static ResourceManager& getInstance();

	//grab a scene from the assets folder and load it into the World Manager
	int loadScene(string name);

	unsigned int loadPNG(const char* path);
	unsigned int loadJPG(const char* path);

	unsigned int defaultTexture;

private:
	ResourceManager();
};