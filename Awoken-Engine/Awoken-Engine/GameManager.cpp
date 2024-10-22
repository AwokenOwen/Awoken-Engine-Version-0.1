#include "GameManager.h"
#include "WindowManager.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "iostream"

using namespace std;

void quit();

//Start all other Managers and get them ready to run the game
int GameManager::Initialize()
{
	cout << "Starting Engine...\n\n";

	if (Window.Initialize())
	{
		cout << "WindowManager failed to start\n";
	}
	cout << "WindowManager started\n";
	if (Input.Initialize())
	{
		cout << "InputManager failed to start\n";
	}
	cout << "InputManager started\n";
	if (Resource.Initialize())
	{
		cout << "ResourceManager failed to start\n";
	}
	cout << "ResourceManager started\n";
	if (World.Initialize())
	{
		cout << "WorldManger failed to start\n";
	}
	cout << "WorldManager started\n";

	//Temporary Escape to Quit for ease of testing
	Input.Escape.add(quit);

	cout << "GameManager Started\n\n";
	return 0;
}

//Run the game AKA the main While loop that lets the game run
void GameManager::Run()
{
	cout << "Starting Game...\n\n";
	cout << "Loading game with scene " << World.getBaseScene() << "\n\n";
	World.loadScene(World.getBaseScene());

	while (!glfwWindowShouldClose(Window.getWindow()))
	{
		Window.Clear();

		Input.processInputs(Window.getWindow());

		World.Update();
		World.LateUpdate();

		Window.Swap();
	}
}

//Shut Down all Managers freeing all data
void GameManager::Terminate()
{
	cout << "Stopping Engine...\n\n";

	Window.Terminate();
	cout << "Shut Down Window Manager\n";
	Input.Terminate();
	cout << "Shut Down Input Manager\n";
	Resource.Terminate(); 
	cout << "Shut Down Resource Manager\n";
	World.Terminate();
	cout << "Shut Down World Manager\n";

	cout << "Shut Down Game Manager\n";
}

//GameManager Singleton
GameManager& GameManager::getInstance()
{
	static GameManager single;
	return single;
}

//Private Constructor for singleton functionallity
GameManager::GameManager()
{
	
}

void quit()
{
	glfwSetWindowShouldClose(Window.getWindow(), GLFW_TRUE);
}
