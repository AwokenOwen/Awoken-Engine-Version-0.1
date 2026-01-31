#include "Camera.h"

Camera::Camera() : Object()
{
    
}

mat4 Camera::getViewMatrix()
{
    return lookAt(GetWorldPosition(), GetWorldPosition() + vec3(0.0f, -0.2f, 1.0f), vec3(0.0f, 1.0f, 0.0f));
}
