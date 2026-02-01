#include "Camera.h"
#include <iostream>

Camera::Camera() : Object()
{
	
}

mat4 Camera::getViewMatrix()
{
	return worldModelMatrix();
}
