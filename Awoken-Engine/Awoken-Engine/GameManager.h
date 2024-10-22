#pragma once

#define GM GameManager::getInstance()

class GameManager
{
public:
	//Start all other Managers and get them ready to run the game
	int Initialize();

	//Run the game AKA the main While loop that lets the game run
	void Run();

	//Shut Down all Managers freeing all data
	void Terminate();

	//GameManager Singleton get function
	static GameManager& getInstance();

private:
	//Private Constructor for singleton functionallity
	GameManager();
};