#pragma once
#include "Component.h"
#include "Mesh.h"
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

using namespace std;

class Material;
class MeshRenderer : public Component
{
public:
	MeshRenderer(Object* _parent);

	MeshRenderer(Object* _parent, const char* path);

	// called every frame
	void Update() override;

	void Draw();

	Material* material;

private:
	vector<Mesh*> meshes;
	string directory;

	void loadModel(string path);
	void processNode(aiNode* node, const aiScene* scene, string path);
	Mesh* processMesh(aiMesh* mesh, const aiScene* scene);
};

