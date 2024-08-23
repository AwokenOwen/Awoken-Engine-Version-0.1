#include "GameManager.h"
#include "WindowManager.h"
#include "InputManager.h"
#include "iostream"

using namespace std;

void quit();

//Start all other Managers and get them ready to run the game
int GameManager::Start()
{
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

	Input.Escape.add(quit);

	return 0;
}

//Run the game AKA the main While loop that lets the game run
void GameManager::Run()
{
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

}

//GameManager Singleton
GameManager& GameManager::getInstance()
{
	static GameManager single;
	return single;
}

//Private Constructor
GameManager::GameManager()
{
	//Private Constructor for singleton functionallity
}

void quit()
{
	glfwSetWindowShouldClose(Window.getWindow(), GLFW_TRUE);
}