#include "DirectionalLight.h"
#include "WorldManager.h"

DirectionalLight::DirectionalLight()
{
	direction = vec3(-1.0f, -1.0f, -1.0f);
	power = 1.0f;
	color = vec3(1.0f, 1.0f, 1.0f);

	World.getActiveScene()->directionalLight = this;
}

DirectionalLight::DirectionalLight(vec3 direction, float power, vec3 color)
{
	this->direction = direction;
	this->power = power;
	this->color = color;

	World.getActiveScene()->directionalLight = this;
}

vec3 DirectionalLight::getDirection()
{
	direction = normalize(direction);
	return direction;
}

float DirectionalLight::getPower()
{
	return power;
}

vec3 DirectionalLight::getColor()
{
	return color;
}

void DirectionalLight::setDirection(vec3 direction)
{
	this->direction = direction;
}

void DirectionalLight::setPower(float power)
{
	this->power = power;
}

void DirectionalLight::setColor(vec3 color)
{
	this->color = color;
}

