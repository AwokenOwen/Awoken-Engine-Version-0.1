#pragma once
#include <functional>
#include <vector>

using namespace std;

class void_event
{
public:
	//default contructor
	void_event();

	//Calls all the functions stored in the _functions vector
	void callEvent();
	//add a function to the _functions vector
	void add(function<void()> function);

private:
	//vector that stores all the function of this event
	vector<function<void()>> _functions;
};