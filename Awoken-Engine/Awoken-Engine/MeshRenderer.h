#pragma once
#include "Component.h"
#include "Mesh.h"

class MeshRenderer : public Component
{
public:
	MeshRenderer();

	MeshRenderer(Mesh* mesh);

	// called first frame if enabled
	void OnEnable() override;
	// called every frame
	void Update() override;

	Mesh* mesh;

private:
	//  render data
	unsigned int VAO, VBO, EBO;

	void setupMesh();

	void Draw();
};

