#include "GameManager.h"
#include "DirectionalLight.h"
#include "WorldManager.h"
#include "MeshRenderer.h"
#include "Material.h"

#include <vector>

int main() 
{
	GM.Initialize();

	new DirectionalLight;
	
	vector<const char*> paths = {
		"assets/defaultAssets/CubeMap/right.jpg",
		"assets/defaultAssets/CubeMap/left.jpg",
		"assets/defaultAssets/CubeMap/top.jpg",
		"assets/defaultAssets/CubeMap/bottom.jpg",
		"assets/defaultAssets/CubeMap/front.jpg",
		"assets/defaultAssets/CubeMap/back.jpg"
	};

	World.getActiveScene()->setSkybox(paths);

	Object* a = new Object;
	a->SetLocalPosition(vec3(0, 0, -5));
	a->SetLocalRotation(quat(vec3(-45, 45, 0)));
	MeshRenderer* m = a->addComponent<MeshRenderer>();
	m->loadModel("assets/defaultAssets/Cube/cube.fbx");
	m->material->setAlbedoTexture("assets/defaultAssets/Cube/Material_Base_color.png", 1);

	GM.Run();

	GM.Terminate();
}