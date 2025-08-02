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

	int addChild(Object* child);

private:
	Object* parent = nullptr;

	vector<Object*> children;

	mat4 modelMatrix();

	vec3 worldPosition();
	vec3 worldRotation();
	vec3 worldScale();

	//update the directional vectors
	void updateDirectionalVectors();

	void setParent(Object* parent);

	vector<Component*> components;
	int componentsSize = 0;

	bool enabled;
};