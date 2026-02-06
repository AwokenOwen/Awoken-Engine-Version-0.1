#include "Cube.h"

Cube::Cube() : Object()
{
	addComponent(new MeshRenderer(this, "assets/defaultAssets/cube.obj"));
}

void Cube::Update()
{
	Object::Update();

	degrees += 0.002f;
	SetLocalRotation(quat(vec3(degrees, degrees, 0)));
}
