#pragma once
#include "glm.hpp"
#include "Object.h"

using namespace glm;

class DirectionalLight : public Object
{
public:
	DirectionalLight(vec3 color = vec3(1.0f, 1.0f, 1.0f), float power = 1.0f);

	vec3 getLookDirection();
	float getPower();
	vec3 getColor();

	void setLookDirection(vec3 direction);
	void setPower(float power);
	void setColor(vec3 color);

private:
	float power;
	vec3 color;
};

