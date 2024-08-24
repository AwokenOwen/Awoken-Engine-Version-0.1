#include "GameManager.h"
#include "WindowManager.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "iostream"

using namespace std;

void quit();

//Start all other Managers and get them ready to run the game
int GameManager::Start()
{
	cout << "Starting Engine...\n\n";

	if (Window.Start())
	{
		cout << "WindowManager failed to start\n";
	}
	cout << "WindowManager started\n";
	if (Input.Start())
	{
		cout << "InputManager failed to start\n";
	}
	cout << "InputManager started\n";
	if (Resource.Start())
	{
		cout << "ResourceManager failed to start\n";
	}
	cout << "ResourceManager started\n";

	//Temporary Escape to Quit for ease of testing
	Input.Escape.add(quit);

	cout << "Game Manager Started\n\n";
	return 0;
}

//Run the game AKA the main While loop that lets the game run
void GameManager::Run()
{
	cout << "Starting Game...\n\n";

	while (!glfwWindowShouldClose(Window.getWindow()))
	{
		Window.Clear();
		Input.processInputs(Window.getWindow());

		Window.Swap();
	}
}

//Shut Down all Managers freeing all data
void GameManager::Stop()
{
	cout << "Stopping Engine...\n\n";

	Window.Stop();
	cout << "Shut Down Window Manager\n";
	Input.Stop();
	cout << "Shut Down Input Manager\n";
	Resource.Stop(); 
	cout << "Shut Down Resource Manager\n";

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
