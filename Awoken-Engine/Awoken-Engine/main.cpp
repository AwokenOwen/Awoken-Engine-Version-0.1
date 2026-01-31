#include "GameManager.h"
#include "Cube.h"
#include "MeshRenderer.h"

void loadObjects() {
	Cube* parent = new Cube();
	Cube* child = new Cube();

	parent->addChild(child);

	parent->SetLocalPosition(vec3(0, 0, 4));

	child->SetLocalScale(vec3(0.5f));
	child->SetLocalPosition(vec3(2, 0, 0));
}

int main() 
{
	GM.Initialize();

	loadObjects();

	GM.Run();

	GM.Terminate();
}