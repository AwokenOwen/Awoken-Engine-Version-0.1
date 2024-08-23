#pragma once
#include <vector>

using namespace std;

class Event
{
public:
	//default contructor
	Event();

	//Calls all the functions stored in the _functions vector
	void callEvent();
	//add a function to the _functions vector
	void add(void (*function)());

private:
	//vector that stores all the function of this event
	vector<void (*)()> _functions;
};