#include "MeshRenderer.h"
#include "WorldManager.h"
#include "WindowManager.h"
#include "ResourceManager.h"
#include "Scene.h"
#include "Mesh.h"
#include "Camera.h"
#include "Material.h"
#include <glad/glad.h>
#include "glm.hpp"
#include "gtc/type_ptr.hpp"
#include <iostream>

MeshRenderer::MeshRenderer(Object* _parent) : Component(_parent)
{
    type = "MeshRenderer";
    material = new Material();
}

MeshRenderer::MeshRenderer(Object* _parent, const char* path) : Component(_parent)
{
    type = "MeshRenderer";
    material = new Material();
    loadModel(path);
}

void MeshRenderer::Update()
{
	for (unsigned int i = 0; i < meshes.size(); i++)
		meshes[i]->Draw();
}

void MeshRenderer::loadModel(string path)
{
    Assimp::Importer import;
    const aiScene* scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        cout << "ERROR::ASSIMP::" << import.GetErrorString() << endl;
        return;
    }
    directory = path.substr(0, path.find_last_of('/'));

    processNode(scene->mRootNode, scene);
}

void MeshRenderer::processNode(aiNode* node, const aiScene* scene)
{
    // process all the node's meshes (if any)
    for (unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(processMesh(mesh, scene));
    }
    // then do the same for each of its children
    for (unsigned int i = 0; i < node->mNumChildren; i++)
    {
        processNode(node->mChildren[i], scene);
    }
}

Mesh* MeshRenderer::processMesh(aiMesh* mesh, const aiScene* scene)
{
    Mesh* mapMesh{};
    if (Resource.getMeshFromMap(*mesh, mapMesh) == 0)
    {
        return mapMesh;
    }

    vector<Mesh::Vertex> vertices;
    vector<unsigned int> indices;

    for (unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        Mesh::Vertex vertex;

        glm::vec3 vector;
        vector.x = mesh->mVertices[i].x;
        vector.y = mesh->mVertices[i].y;
        vector.z = mesh->mVertices[i].z;
        vertex.position = vector;

        vector.x = mesh->mNormals[i].x;
        vector.y = mesh->mNormals[i].y;
        vector.z = mesh->mNormals[i].z;
        vertex.normal = vector;

        if (mesh->mTextureCoords[0]) // does the mesh contain texture coordinates?
        {
            glm::vec2 vec;
            vec.x = mesh->mTextureCoords[0][i].x;
            vec.y = mesh->mTextureCoords[0][i].y;
            vertex.texCoords = vec;
        }
        else
            vertex.texCoords = glm::vec2(0.0f, 0.0f);

        vertices.push_back(vertex);
    }
    // process indices
    for (unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; j++)
            indices.push_back(face.mIndices[j]);
    }

    Mesh* _mesh = new Mesh(vertices, indices);
    _mesh->setParent(getParent());
    _mesh->material = material;

    return _mesh;
}
