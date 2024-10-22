#include "Component.h"

Component::Component()
{
	parent = nullptr;
	enabled = true;
}

Component::Component(Object* _parent)
{
	parent = _parent;
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

Object* Component::getParent()
{
	return parent;
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

void Component::to_json(json& j, const Component& p)
{

}

void Component::from_json(const json& j, Component& p)
{

}

bool Component::getActiveState()
{
	return enabled;
}
