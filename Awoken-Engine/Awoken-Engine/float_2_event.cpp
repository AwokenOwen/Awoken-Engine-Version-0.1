#include "float_2_event.h"

//default contructor
float_2_event::float_2_event()
{
}

//Calls all the functions stored in the _functions vector
void float_2_event::callEvent(float x, float y)
{
	for (int i = 0; i < _functions.size(); i++)
	{
		(*_functions[0])(x, y);
	}
}

//add a function to the _functions vector
void float_2_event::add(void(*function)(float x, float y))
{
	_functions.push_back(function);
}

