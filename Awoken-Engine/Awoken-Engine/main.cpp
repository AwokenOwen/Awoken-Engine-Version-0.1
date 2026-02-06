#include "GameManager.h"
#include "Cube.h"
#include "MeshRenderer.h"
#include "Material.h"
#include "ResourceManager.h"
#include "DirectionalLight.h"

void loadObjects() {

	DirectionalLight* sun = new DirectionalLight();
	sun->setPower(0.5f);

	Cube* a = new Cube();
	a->SetLocalPosition(vec3(0, 0, -3.0f));
	a->SetLocalScale(vec3(1.0f));

	Material* aMaterial = dynamic_cast<MeshRenderer*>(a->getComponent("MeshRenderer"))->material;

	aMaterial->setAlbedoTexture("assets/cubeBaseColor.png");
	aMaterial->setShaderProgram("shaders/PBRVertex.vert", "shaders/PBRFragment.frag");
}

int main() 
{
	GM.Initialize();

	loadObjects();

	GM.Run();

	GM.Terminate();
}