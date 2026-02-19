#include "Camera.h"
#include <iostream>

Camera::Camera() : Object()
{
	
}

mat4 Camera::getViewMatrix()
{
	worldModelMatrix();
	return lookAt(GetWorldPosition(), GetWorldPosition() + forward, up);
}
