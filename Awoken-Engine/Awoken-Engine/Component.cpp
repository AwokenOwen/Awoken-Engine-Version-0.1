#include "Component.h"

Component::Component()
{
	parent = nullptr;
	enabled = true;
}

void Component::Awake()
{

}

void Component::OnEnable()
{
	
}

void Component::Start()
{

}

void Component::Update()
{

}

void Component::LateUpdate()
{

}

void Component::OnDisable()
{

}

void Component::setParent(Object* parent)
{
	this->parent = parent;
}

void Component::setActive(bool activeState)
{
	if (activeState != enabled)
	{
		if (activeState)
		{
			OnEnable();
		}
		else
		{
			OnDisable();
		}
		enabled = activeState;
	}
}

bool Component::getActiveState()
{
	return enabled;
}
