#pragma once
#include <vector>

using namespace std;

class MouseEvent
{
public:
	//default contructor
	MouseEvent();

	//Calls all the functions stored in the _functions vector
	void callEvent(float x, float y);
	//add a function to the _functions vector
	void add(void (*function)(float x, float y));

private:
	//vector that stores all the function of this event
	vector<void (*)(float x, float y)> _functions;
};
