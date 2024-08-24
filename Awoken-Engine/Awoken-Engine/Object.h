#pragma once
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include <vector>

using namespace glm;
using namespace std;

struct Transform
{
	vec3 localPosition;
	//pitch, yaw, roll, rotations
	vec3 localRotation;
	vec3 localScale;

	vec3 forward;
	vec3 up;
	vec3 right;

	Transform() 
	{
		localPosition = vec3(0.0f);
		localRotation = vec3(0.0f);
		localScale = vec3(1.0f);

		forward = vec3(0.0f, 0.0f, 1.0f);
		up = vec3(0.0f, 1.0f, 0.0f);
		right = vec3(1.0f, 0.0f, 0.0f);
	}

	//update the directional vectors
	vec3 updateDirectionalVectors() 
	{
		forward.x = sin(localRotation.y);
		forward.y = -(sin(localPosition.x) * cos(localRotation.y));
		forward.z = -(cos(localRotation.x) * cos(localRotation.y));

		right.x = sin(localRotation.y);
		right.y = -(sin(localPosition.z) * cos(localRotation.y));
		right.z = -(cos(localRotation.z) * cos(localRotation.y));

		up = cross(forward, right);
	}
};

class Component;
class Object
{
public:
	//Default contructor adds itself to the world list
	Object();

	//called once at the start of a scene
	virtual void Awake();
	//called once at the start of the frame it is enabled on
	virtual void OnEnable();
	//called on the first frame if enabled
	virtual void Start();
	//called every frame
	virtual void Update();
	//called every frame after update
	virtual void LateUpdate();
	//called on the last frame it is enabled
	virtual void OnDisable();
	//to be called when Destroying it self
	virtual void Destroy();

	//get the parent object if there is one
	Object* getParent();

	void addComponent(Component* component);

	//transfrom data stored here
	Transform transform;

	void setActive(bool activeState);
	bool getActiveState();

private:
	Object* parent = nullptr;

	vector<Object*> children;

	mat4 modelMatrix();

	vec3 worldPosition();
	vec3 worldRotation();
	vec3 worldScale();

	void setParent(Object* parent);
	void setChild(Object* child);

	vector<Component*> components;
	int componentsSize = 0;

	bool enabled;

};