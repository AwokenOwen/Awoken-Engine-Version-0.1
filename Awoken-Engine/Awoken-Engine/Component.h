#pragma once

#include <string>

using namespace std;

class Object;
class Component
{
public:
	//default contructor
	Component();
	Component(Object* _parent);

	string type;

	//called once at the start of a scene
	virtual void Awake();
	//called once at the start of the frame the object is enabled on
	virtual void OnEnable();
	//called on the first frame if enabled
	virtual void Start();
	//called every frame
	virtual void Update();
	//called every frame after update
	virtual void LateUpdate();
	//called on the last frame it is enabled
	virtual void OnDisable();

	Object* getParent();

	bool getActiveState();
	void setActive(bool activeState);

private:
	Object* parent = nullptr;

	bool enabled;
};