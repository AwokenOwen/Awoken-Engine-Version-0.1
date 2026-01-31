#pragma once

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/quaternion.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include <gtx/euler_angles.hpp>
#include <vector>

using namespace glm;
using namespace std;

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

	void setActive(bool activeState);
	bool getActiveState();

	int addChild(Object* child);

	vec3 GetWorldPosition();
	quat GetWorldRotation();
	vec3 GetWorldScale();

	mat4 worldModelMatrix();

	vec3 GetLocalPosition();
	quat GetLocalRotation();
	vec3 GetLocalScale();

	mat4 localModelMatrix();

	void SetLocalPosition(vec3 location);
	void SetLocalRotation(quat rotation);
	void SetLocalScale(vec3 scale);

private:
	Object* parent = nullptr;

	vector<Object*> children;

	void setParent(Object* parent);

	vector<Component*> components;
	int componentsSize = 0;

	bool enabled;

	vec3 localPosition;
	//pitch, yaw, roll, rotations
	quat localRotation;
	vec3 localScale;

	vec3 worldPosition;
	//pitch, yaw, roll, rotations
	quat worldRotation;
	vec3 worldScale;

	vec3 skew;
	vec4 perspective;

	bool firstFrame = true;

	float degree;
};