#include "Camera.h"
#include <iostream>

Camera::Camera() : Object()
{
	alpha = 0;
}

mat4 Camera::getViewMatrix()
{
	worldModelMatrix();

	//replace vec3(0.0) with GetWorldPosition() + forward
	return lookAt(GetWorldPosition(), vec3(0.0), up);
}

void Camera::Update()
{
	alpha += 0.005;
	SetLocalPosition(vec3(5 * sin(alpha), 0.0f, 5 * cos(alpha)));

	Object::Update();
}
