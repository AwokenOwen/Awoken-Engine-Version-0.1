#include "Event.h"

//default contructor
Event::Event()
{
}

//Calls all the functions stored in the _functions vector
void Event::callEvent()
{
	for (int i = 0; i < _functions.size(); i++)
	{
		(*_functions[i])();
	}
}

//add a function to the _functions vector
void Event::add(void(*function)())
{
	_functions.push_back(function);
}