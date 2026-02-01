#include "Cube.h"

Cube::Cube() : Object()
{
	vector<Mesh::Vertex> squareVertices = {
		Mesh::Vertex(vec3(.5,.5, .5), vec3(0, 0, -1), vec2(1,1)),
		Mesh::Vertex(vec3(.5,-.5, .5), vec3(0, 0, -1), vec2(1,0)),
		Mesh::Vertex(vec3(-.5,-.5, .5), vec3(0, 0, -1), vec2(0,0)),
		Mesh::Vertex(vec3(-.5,.5, .5), vec3(0, 0, -1), vec2(0,1)),

		Mesh::Vertex(vec3(.5,.5, -.5), vec3(0, 0, -1), vec2(1,1)),
		Mesh::Vertex(vec3(.5,-.5, -.5), vec3(0, 0, -1), vec2(1,0)),
		Mesh::Vertex(vec3(-.5,-.5, -.5), vec3(0, 0, -1), vec2(0,0)),
		Mesh::Vertex(vec3(-.5,.5, -.5), vec3(0, 0, -1), vec2(0,1)),

		Mesh::Vertex(vec3(.5,.5, .5), vec3(0, 0, -1), vec2(1,1)),
		Mesh::Vertex(vec3(.5,.5, -.5), vec3(0, 0, -1), vec2(1,0)),
		Mesh::Vertex(vec3(.5,-.5, -.5), vec3(0, 0, -1), vec2(0,0)),
		Mesh::Vertex(vec3(.5,-.5, .5), vec3(0, 0, -1), vec2(0,1)),

		Mesh::Vertex(vec3(-.5,.5, .5), vec3(0, 0, -1), vec2(1,1)),
		Mesh::Vertex(vec3(-.5,.5, -.5), vec3(0, 0, -1), vec2(1,0)),
		Mesh::Vertex(vec3(-.5,-.5, -.5), vec3(0, 0, -1), vec2(0,0)),
		Mesh::Vertex(vec3(-.5,-.5, .5), vec3(0, 0, -1), vec2(0,1)),

		Mesh::Vertex(vec3(.5,.5, .5), vec3(0, 0, -1), vec2(1,1)),
		Mesh::Vertex(vec3(.5,.5, -.5), vec3(0, 0, -1), vec2(1,0)),
		Mesh::Vertex(vec3(-.5,.5, -.5), vec3(0, 0, -1), vec2(0,0)),
		Mesh::Vertex(vec3(-.5,.5, .5), vec3(0, 0, -1), vec2(0,1)),

		Mesh::Vertex(vec3(.5,-.5, .5), vec3(0, 0, -1), vec2(1,1)),
		Mesh::Vertex(vec3(.5,-.5, -.5), vec3(0, 0, -1), vec2(1,0)),
		Mesh::Vertex(vec3(-.5,-.5, -.5), vec3(0, 0, -1), vec2(0,0)),
		Mesh::Vertex(vec3(-.5,-.5, .5), vec3(0, 0, -1), vec2(0,1)),
	};

	vector<unsigned int> squareIndices = {
		0, 1, 3,
		1, 2, 3,

		4, 5, 7,
		5, 6, 7,

		8, 9, 11,
		9, 10, 11,

		12, 13, 15,
		13, 14, 15,

		16, 17, 19,
		17, 18, 19,

		20, 21, 23,
		21, 22, 23,
	};

	addComponent(new MeshRenderer(this, new Mesh(squareVertices, squareIndices)));
}

void Cube::Update()
{
	Object::Update();

	degrees += 0.002f;
	SetLocalRotation(quat(vec3(degrees, degrees, 0)));
}
