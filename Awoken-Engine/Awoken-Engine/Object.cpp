#include "Object.h"
#include "Component.h"
#include "iostream"

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

mat4 Object::modelMatrix()
{
	mat4 model = mat4(1.0f);

	model = translate(model, worldPosition());
	float angle = 0;
	vec3 rotationVec;
	if (worldRotation().x > angle)
	{
		angle = worldRotation().x;
	}
	if (worldRotation().y > angle)
	{
		angle = worldRotation().y;
	}
	if (worldRotation().z > angle)
	{
		angle = worldRotation().z;
	}

	if (angle > 0)
	{
		rotationVec = worldRotation() / angle;
	}
	else
	{
		rotationVec = glm::vec3(1.0f);
	}

	model = rotate(model, radians(angle), rotationVec); 
	model = scale(model, worldScale());

	return model;
}

vec3 Object::worldPosition()
{
	if (parent == nullptr)
	{
		return transform.localPosition;
	}

	vec3 worldPos = vec3(0);

	Object* currentParent = parent;
	vec3 currentPos = transform.localPosition;

	while (currentParent != nullptr)
	{
		parent->updateDirectionalVectors();

		worldPos += 
			currentParent->transform.right * currentPos.x +
			currentParent->transform.up * currentPos.y +
			currentParent->transform.forward * currentPos.z;

		currentPos = currentParent->transform.localPosition;
		currentParent = currentParent->getParent();
	}

	worldPos += currentPos;

	return worldPos;
}

vec3 Object::worldRotation()
{
	vec3 worldRot = transform.localRotation;

	Object* currentParent = parent; 

	while (currentParent != nullptr)
	{
		worldRot += currentParent->transform.localRotation; 

		currentParent = currentParent->getParent(); 
	}

	return worldRot;
}

vec3 Object::worldScale()
{
	vec3 worldSca = vec3(1.0f);

	Object* currentParent = parent;

	while (currentParent != nullptr)
	{
		worldSca *= currentParent->transform.localScale;

		currentParent = currentParent->getParent();
	}

	return worldSca;
}

void Object::updateDirectionalVectors()
{
	transform.forward.x = sin(worldRotation().y);
	transform.forward.y = -(sin(worldRotation().x) * cos(worldRotation().y)); 
	transform.forward.z = -(cos(worldRotation().x) * cos(worldRotation().y)); 

	transform.right.x = sin(worldRotation().y);
	transform.right.y = -(sin(worldRotation().z) * cos(worldRotation().y)); 
	transform.right.z = -(cos(worldRotation().z) * cos(worldRotation().y)); 

	transform.up = cross(transform.forward, transform.right); 
}

void Object::setParent(Object* parent)
{
	this->parent = parent;
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
