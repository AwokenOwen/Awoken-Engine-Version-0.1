#include "Event.h"

Event::Event()
{

}

void Event::callEvent()
{
	for (int i = 0; i < _functions.size(); i++)
	{
		(*_functions[0])();
	}
}

void Event::add(void(*function)())
{
	_functions.push_back(function);
}