#pragma once
#include "glm.hpp"

using namespace glm;

class DirectionalLight
{
public:
	DirectionalLight();

	DirectionalLight(vec3 direction, float power = 1.0f, vec3 color = vec3(1.0f, 1.0f, 1.0f));

	vec3 getDirection();
	float getPower();
	vec3 getColor();

	void setDirection(vec3 direction);
	void setPower(float power);
	void setColor(vec3 color);

private:
	vec3 direction;
	float power;
	vec3 color;
};

