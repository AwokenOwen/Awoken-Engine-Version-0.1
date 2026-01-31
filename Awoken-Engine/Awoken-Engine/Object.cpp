#include "Object.h"
#include "Component.h"
#include "iostream"
#include <gtx/matrix_decompose.hpp>

//Default contructor adds itself to the world list
Object::Object()
{
	//set default variables add to the ToBeAdded vector in WorldManager (Coming soon)
	enabled = true;
}

//called once at the start of a scene
void Object::Awake()
{
	for (int i = 0; i < componentsSize; i++)
	{
		if (components[i]->getActiveState())
		{
			components[i]->Awake();
		}
	}
}

//called once at the start of the frame it is enabled on
void Object::OnEnable()
{
	for (int i = 0; i < componentsSize; i++)
	{
		if (components[i]->getActiveState())
		{
			components[i]->OnEnable();
		}
	}

	enabled = true;
}

//called on the first frame if enabled
void Object::Start()
{
	for (int i = 0; i < componentsSize; i++)
	{
		if (components[i]->getActiveState())
		{
			components[i]->Start();
		}
	}
}

//called every frame
void Object::Update()
{
	for (int i = 0; i < componentsSize; i++)
	{
		if (components[i]->getActiveState())
		{
			components[i]->Update();
		}
	}
}

//called every frame after update
void Object::LateUpdate()
{
	for (int i = 0; i < componentsSize; i++)
	{
		if (components[i]->getActiveState())
		{
			components[i]->LateUpdate();
		}
	}
}

//called on the last frame it is enabled
void Object::OnDisable()
{
	for (int i = 0; i < componentsSize; i++)
	{
		if (components[i]->getActiveState())
		{
			components[i]->OnDisable();
		}
	}
	enabled = false;
}

void Object::Destroy()
{
	OnDisable();

	components.clear();

	for (int i = 0; i < children.size(); i++)
	{
		children[i]->Destroy();
	}
	delete this;
}

//return parent object if there is one
Object* Object::getParent()
{
	return parent;
}

void Object::addComponent(Component* component)
{
	components.push_back(component);
	componentsSize++;
}

void Object::setActive(bool activeState)
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

bool Object::getActiveState()
{
	return enabled;
}

mat4 Object::localModelMatrix()
{
	mat4 model = mat4(1.0f);

	model = scale(model, GetWorldScale());
	model = rotate(model, GetWorldRotation());
	model = translate(model, GetWorldScale());

	return model;
}

mat4 Object::worldModelMatrix()
{
	mat4 worldModelMatrix = localModelMatrix();

	Object* current = parent;
	while (current != nullptr) {
		worldModelMatrix = worldModelMatrix * current->localModelMatrix();
		current = current->parent;
	}
	
	decompose(worldModelMatrix, worldScale, worldRotation, worldLocation, skew, perspective);

	return worldModelMatrix;
}

void Object::setParent(Object* parent)
{
	this->parent = parent;
}

mat4 Object::rotate(mat4 matrix, quat rotationVector)
{
	return glm::rotate(matrix, rotationVector.x, vec3(1, 0, 0)) * glm::rotate(matrix, rotationVector.y, vec3(0, 1, 0)) * glm::rotate(matrix, rotationVector.z, vec3(0, 0, 1));
}


int Object::addChild(Object* child) 
{
	Object* current = parent;
	while (current != nullptr)
	{
		if (current == child)
		{
			std::cout << "Error: Child is currently a parent of Object\n";
			return 1;
		}
		current = current->getParent();
	}

	child->setParent(this); 
	children.push_back(child);
	return 0;
}

vec3 Object::GetWorldPosition()
{
	return worldLocation;
}

quat Object::GetWorldRotation()
{
	return worldRotation;
}

vec3 Object::GetWorldScale()
{
	return worldScale;
}

vec3 Object::GetLocalPosition()
{
	return localPosition;
}

quat Object::GetLocalRotation()
{
	return localRotation;
}

vec3 Object::GetLocalScale()
{
	return localScale;
}

void Object::SetLocalPosition(vec3 location)
{
	localPosition = location;
}

void Object::SetLocalRotation(quat rotation)
{
	localRotation = rotation;
}

void Object::SetLocalScale(vec3 scale)
{
	localScale = scale;
}
