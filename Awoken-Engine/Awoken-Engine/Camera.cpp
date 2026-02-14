#include "Camera.h"
#include <iostream>

Camera::Camera() : Object()
{
	
}

mat4 Camera::getViewMatrix()
{
	mat4 viewMatrix = translate(mat4(1.0f), -GetWorldPosition());
	viewMatrix = rotate(viewMatrix, -angle(GetWorldRotation()), axis(GetWorldRotation()));

	return viewMatrix;
}
