#pragma once
#include <vector>

using namespace std;

class MouseEvent
{
public:
	MouseEvent();

	void callEvent(float x, float y);
	void add(void (*function)(float x, float y));

private:
	vector<void (*)(float x, float y)> _functions;
};
