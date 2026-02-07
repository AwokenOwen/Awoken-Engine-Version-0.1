#include "GameManager.h"
#include "Cube.h"
#include "MeshRenderer.h"
#include "Material.h"
#include "ResourceManager.h"
#include "DirectionalLight.h"

void loadObjects() {

	DirectionalLight* sun = new DirectionalLight();
	sun->setPower(1.0f);

	Cube* a = new Cube();
	a->SetLocalPosition(vec3(0, 0, -3.0f));
	a->SetLocalScale(vec3(1.0f));

	Material* mat = dynamic_cast<MeshRenderer*>(a->getComponent("MeshRenderer"))->material;

	//mat->setAlbedoTexture("assets/cubeBaseColor.png");
}

int main() 
{
	GM.Initialize();

	loadObjects();

	GM.Run();

	GM.Terminate();
}