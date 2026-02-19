#include "GameManager.h"
#include "DirectionalLight.h"
#include "WorldManager.h"
#include "MeshRenderer.h"
#include "Camera.h"
#include "Material.h"
#include "Mesh.h"

#include <vector>

int main() 
{
	GM.Initialize();

	new DirectionalLight;
	
	vector<const char*> paths = {
		"assets/defaultAssets/Skybox/right.jpg",
		"assets/defaultAssets/Skybox/left.jpg",
		"assets/defaultAssets/Skybox/top.jpg",
		"assets/defaultAssets/Skybox/bottom.jpg",
		"assets/defaultAssets/Skybox/front.jpg",
		"assets/defaultAssets/Skybox/back.jpg"
	};

	World.getActiveScene()->setSkybox(paths);

	Object* a = new Object;
	a->SetLocalPosition(vec3(0, 0, 0));
	a->SetLocalRotation(quat(vec3((3.14f/2.0f), 0, 0)));
	MeshRenderer* m = a->addComponent<MeshRenderer>();
	m->loadModel("assets/defaultAssets/cube.fbx");

	GM.Run();

	GM.Terminate();
}