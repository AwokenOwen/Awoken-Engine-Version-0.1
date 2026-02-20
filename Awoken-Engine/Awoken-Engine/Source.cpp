#include "GameManager.h"
#include "DirectionalLight.h"
#include "WorldManager.h"
#include "MeshRenderer.h"
#include "Camera.h"
#include "Material.h"
#include "Mesh.h"

#include <vector>
#include <iostream>

int main() 
{
	GM.Initialize();

	new DirectionalLight;

	World.getActiveScene()->loadDefaultSkybox();
	World.getActiveScene()->getCamera()->SetLocalPosition(vec3(0, 1, 0));

	Object* a = new Object;
	a->SetLocalPosition(vec3(0, -1, 0));
	a->SetLocalScale(vec3(5));
	MeshRenderer* m = a->addComponent<MeshRenderer>();
	m->loadModel("assets/defaultAssets/plane.fbx");
	m->material->setShaderProgram("assets/Shaders/grassPlane.vert", "assets/Shaders/grassPlane.frag");

	int i = 0;
	for (int x = -40; x < 40; x++)
	{
		for (int z = -40; z < 40; z++)
		{
			std::cout << i << std::endl;
			Object* b = new Object;
			b->SetLocalPosition(vec3(x * 0.4f, 0.0f, z * 0.4f));
			b->SetLocalScale(vec3(0.5f));
			b->SetLocalRotation(quat(vec3(glm::radians(-90.0f), 0.0f, 0.0f)));
			MeshRenderer* mr = b->addComponent<MeshRenderer>();
			mr->loadModel("assets/Models/Grass.fbx");
			mr->material->twoSided = true;
			mr->material->setShaderProgram("assets/Shaders/grass.vert", "assets/Shaders/grass.frag");
			mr->material->setTexture("assets/Textures/DefaultMaterial_Base_color.png");
			i++;
		}
	}

	GM.Run();

	GM.Terminate();
}