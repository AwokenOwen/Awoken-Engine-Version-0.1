#include "Plane.h"
#include <vector>
#include "Mesh.h"
#include "MeshRenderer.h"

Plane::Plane()
{
	vector<Mesh::Vertex> squareVertices = {
		Mesh::Vertex(vec3(.5,.5, 0), vec3(0, 0, -1), vec2(1,1)),
		Mesh::Vertex(vec3(.5,-.5, 0), vec3(0, 0, -1), vec2(1,0)),
		Mesh::Vertex(vec3(-.5,-.5, 0), vec3(0, 0, -1), vec2(0,0)),
		Mesh::Vertex(vec3(-.5,.5, 0), vec3(0, 0, -1), vec2(0,1))
	};

	vector<unsigned int> squareIndices = {
		0, 1, 3,
		1, 2, 3
	};

	addComponent(new MeshRenderer(this, new Mesh(squareVertices, squareIndices)));
}
