#include "GameManager.h"
#include "Plane.h"
#include "Cube.h"
#include "MeshRenderer.h"
#include "ResourceManager.h"

void loadObjects() {

	//Plane* a = new Plane();
	Cube* a = new Cube();
	a->SetLocalPosition(vec3(0, 0, -1.5f));
	a->SetLocalScale(vec3(1.0f));

	MeshRenderer* meshRenderer = dynamic_cast<MeshRenderer*>(a->getComponent("MeshRenderer"));

	vector<Mesh::Texture> texture = {
		Mesh::Texture(Resource.loadPNG("assets/container.png"), "diffuse")
	};

	meshRenderer->mesh->addTexture(texture);
}

int main() 
{
	GM.Initialize();

	loadObjects();

	GM.Run();

	GM.Terminate();
}