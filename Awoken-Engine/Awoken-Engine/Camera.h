#pragma once
#include "Object.h"

class Camera : public Object
{
public:
	Camera();

	mat4 getViewMatrix();

	void Update() override;

	float alpha;
};

