#pragma once
#include "Object.h"
#include "Mesh.h"
#include "MeshRenderer.h"

class Cube : public Object
{
public:
	Cube();

	void Update() override;
};

