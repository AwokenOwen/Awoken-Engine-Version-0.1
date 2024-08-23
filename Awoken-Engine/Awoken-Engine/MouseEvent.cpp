#include "MouseEvent.h"

MouseEvent::MouseEvent()
{
}

void MouseEvent::callEvent(float x, float y)
{
	for (int i = 0; i < _functions.size(); i++)
	{
		(*_functions[0])(x, y);
	}
}

void MouseEvent::add(void(*function)(float x, float y))
{
	_functions.push_back(function);
}

