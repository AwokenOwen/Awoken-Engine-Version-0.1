#include "PointLight.h"

PointLight::PointLight()
{
	position = vec3(0.0f);
	constant = 1.0f;
	linear = 1.0f;
	quadratic = 1.0f;
	color = vec3(1.0f, 1.0f, 1.0f);
}

PointLight::PointLight(vec3 position, float constant, float linear, float quadratic, vec3 color)
{
	this->position = position;
	this->constant = constant;
	this->linear = linear;
	this->quadratic = quadratic;
	this->color = color;
}
