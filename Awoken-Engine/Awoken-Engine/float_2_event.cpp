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
		_functions[0](x, y);
	}
}

void float_2_event::add(function<void(float x, float y)> function) 
{
	_functions.push_back(function);
}

