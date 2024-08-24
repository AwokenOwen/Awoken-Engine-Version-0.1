#pragma once
#include <fstream>
#include <string>

using namespace std;

#define Resource ResourceManager::getInstance()

class ResourceManager
{
public:
	//Start the Resource Manager make folders and files nessesary for running the game if not made already
	int Start();

	//close files and stop the Resource Manager
	void Stop();

	//Singleton get function
	static ResourceManager& getInstance();

	//grab a scene from the assets folder and load it into the World Manager
	int loadScene(string name);

	//Save all the necessary files for game preformance
	int saveGame();

private:
	ResourceManager();

	string path;
};