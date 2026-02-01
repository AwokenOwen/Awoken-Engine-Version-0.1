#pragma once
#include <functional>
#include <vector>

using namespace std;

class float_2_event
{
public:
	//default contructor
	float_2_event();

	//Calls all the functions stored in the _functions vector
	void callEvent(float x, float y);
	//add a function to the _functions vector
	void add(function<void(float x, float y)> function);

private:
	//vector that stores all the function of this event
	vector<function<void(float x, float y)>> _functions;
};
