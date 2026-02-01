#pragma once
#include "Object.h"

class Camera : public Object
{
public:
	Camera();

	Camera(bool controller);

	mat4 getViewMatrix();

	void Update() override;

private:

	vec2 moveInput = vec2();
	float phi = 3.14f / 2.0f;
	float theta = 3.14f / 2.0f;

	mat4 viewMatrix;

	void wPressed();
	void sPressed();
	void dPressed();
	void aPressed();
	void mouseHandler(float x, float y);

};

