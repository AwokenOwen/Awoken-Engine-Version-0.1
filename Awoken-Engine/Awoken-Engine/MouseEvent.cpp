#include "MouseEvent.h"

//default contructor
MouseEvent::MouseEvent()
{
}

//Calls all the functions stored in the _functions vector
void MouseEvent::callEvent(float x, float y)
{
	for (int i = 0; i < _functions.size(); i++)
	{
		(*_functions[0])(x, y);
	}
}

//add a function to the _functions vector
void MouseEvent::add(void(*function)(float x, float y))
{
	_functions.push_back(function);
}

