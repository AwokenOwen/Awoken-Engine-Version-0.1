#include "Cube.h"

Cube::Cube() : Object()
{
	vector<Mesh::Vertex> squareVertices = {
		Mesh::Vertex(vec3(.5,.5, .5), vec3(0, 0, -1), vec2(0,0)),
		Mesh::Vertex(vec3(.5,-.5, .5), vec3(0, 0, -1), vec2(0,0)),
		Mesh::Vertex(vec3(-.5,-.5, .5), vec3(0, 0, -1), vec2(0,0)),
		Mesh::Vertex(vec3(-.5,.5, .5), vec3(0, 0, -1), vec2(0,0)),

		Mesh::Vertex(vec3(.5,.5, -.5), vec3(0, 0, -1), vec2(0,0)),
		Mesh::Vertex(vec3(.5,-.5, -.5), vec3(0, 0, -1), vec2(0,0)),
		Mesh::Vertex(vec3(-.5,-.5, -.5), vec3(0, 0, -1), vec2(0,0)),
		Mesh::Vertex(vec3(-.5,.5, -.5), vec3(0, 0, -1), vec2(0,0)),
	};

	vector<unsigned int> squareIndices = {
		0, 1, 3,
		1, 2, 3,
		0, 1, 4,
		1, 4, 5,
		2, 3, 6,
		3, 6, 7,
		0, 2, 6,
		0, 4, 6,
		1, 3, 7,
		1, 5, 7,
		4, 5, 7,
		5, 6, 7,
	};

	addComponent(new MeshRenderer(this, new Mesh(squareVertices, squareIndices)));
}

void Cube::Update()
{
	Object::Update();
	degree += 0.001f;
	SetLocalRotation(quat(vec3(0, degree, 0)));
}
