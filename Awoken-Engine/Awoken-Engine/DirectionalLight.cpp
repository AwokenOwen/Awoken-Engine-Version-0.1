#include "DirectionalLight.h"
#include "WorldManager.h"

DirectionalLight::DirectionalLight(vec3 color, float power) : Object()
{
	this->power = power;
	this->color = color;

	setLookDirection(vec3(-1.0, -1.0, -1.0));

	World.getActiveScene()->directionalLight = this;
}

vec3 DirectionalLight::getLookDirection()
{
	return normalize(GetForward());
}

float DirectionalLight::getPower()
{
	return power;
}

vec3 DirectionalLight::getColor()
{
	return color;
}

void DirectionalLight::setLookDirection(vec3 direction)
{
	SetLocalRotation(quat(lookAt(normalize(direction), vec3(0.0), vec3(0.0, 1.0, 0.0))));
}

void DirectionalLight::setPower(float power)
{
	this->power = power;
}

void DirectionalLight::setColor(vec3 color)
{
	this->color = color;
}

