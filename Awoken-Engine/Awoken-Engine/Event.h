#pragma once
#include <vector>

using namespace std;

class Event
{
public:
	Event();

	void callEvent();
	void add(void (*function)());

private:
	vector<void (*)()> _functions;
};