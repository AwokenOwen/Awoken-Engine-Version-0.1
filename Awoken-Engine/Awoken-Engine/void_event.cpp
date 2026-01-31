#include "void_event.h"

//default contructor
void_event::void_event()
{
}

//Calls all the functions stored in the _functions vector
void void_event::callEvent()
{
	for (int i = 0; i < _functions.size(); i++)
	{
		(*_functions[i])();
	}
}

//add a function to the _functions vector
void void_event::add(void(*function)())
{
	_functions.push_back(function);
}