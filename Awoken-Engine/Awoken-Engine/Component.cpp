#include "Component.h"

Component::Component()
{
	parent = nullptr;
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
