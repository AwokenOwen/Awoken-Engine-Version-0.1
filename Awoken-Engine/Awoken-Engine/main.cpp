#include "GameManager.h"
#include "Object.h"
#include "MeshRenderer.h"

void loadObjects() {
	Object* test = new Object();

	vector<Mesh::Vertex> squareVertices = {
		Mesh::Vertex(vec3(.5,.5, 0), vec3(0, 0, -1), vec2(0,0)),
		Mesh::Vertex(vec3(.5,-.5, 0), vec3(0, 0, -1), vec2(0,0)),
		Mesh::Vertex(vec3(-.5,-.5, 0), vec3(0, 0, -1), vec2(0,0)),
		Mesh::Vertex(vec3(-.5,.5, 0), vec3(0, 0, -1), vec2(0,0))
	};

	 vector<unsigned int> squareIndices = {
		0, 1, 3, 
		1, 2, 3 
	};



	test->addComponent(new MeshRenderer(test, new Mesh(squareVertices, squareIndices)));
}

int main() 
{
	GM.Initialize();

	loadObjects();

	GM.Run();

	GM.Terminate();
}