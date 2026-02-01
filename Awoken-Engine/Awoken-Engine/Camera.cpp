#include "Camera.h"
#include "InputManager.h"
#include <iostream>

Camera::Camera() : Object()
{
	viewMatrix = lookAt(GetWorldPosition(), GetWorldPosition() + vec3(0.0f, -0.2f, 1.0f), vec3(0.0f, 1.0f, 0.0f));
}

Camera::Camera(bool controller) : Object()
{
	viewMatrix = lookAt(GetWorldPosition(), GetWorldPosition() + vec3(0.0f, -0.2f, 1.0f), vec3(0.0f, 1.0f, 0.0f));

	if (controller)
	{
		function<void()> w = [this]() {wPressed(); };
		Input.W_Pressed.add(w);

		function<void()> s = [this]() {sPressed(); };
		Input.S_Pressed.add(s);

		function<void()> d = [this]() {dPressed(); };
		Input.D_Pressed.add(d);

		function<void()> a = [this]() {aPressed(); };
		Input.A_Pressed.add(a);

		function<void(float, float)> m = [this](float x, float y) {mouseHandler(x, y); };
		Input.MouseOffset.add(m);
	}
}

mat4 Camera::getViewMatrix()
{
	return worldModelMatrix();
}

void Camera::Update()
{
	Object::Update();

	vec3 moveVector = GetForward() * moveInput.y + GetRight() * moveInput.x;

	//SetLocalRotation(lookAt(GetWorldPosition(), GetWorldPosition() + vec3(sin(phi) * cos(theta), cos(phi), sin(phi) * sin(theta)), vec3(0.0f, 1.0f, 0.0f)));
	SetLocalPosition(GetLocalPosition() + (moveVector * 0.001f));
}

void Camera::wPressed()
{
	
}

void Camera::sPressed()
{
	
}

void Camera::dPressed()
{
	
}

void Camera::aPressed()
{
	
}

void Camera::mouseHandler(float x, float y)
{
	
}
