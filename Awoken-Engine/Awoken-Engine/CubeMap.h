#pragma once
#include "Mesh.h"

class CubeMap : public Mesh
{
public:
	CubeMap(vector<const char*> paths, float size);

	void Draw() override;
};

