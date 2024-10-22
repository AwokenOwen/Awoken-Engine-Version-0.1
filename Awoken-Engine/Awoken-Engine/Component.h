#pragma once
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Object;
class Component
{
public:
	//default contructor
	Component();
	Component(Object* _parent);

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

	virtual void to_json(json& j, const Component& p);

	virtual void from_json(const json& j, Component& p);

private:
	Object* parent = nullptr;

	bool enabled;
};