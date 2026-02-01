#include "Mesh.h"

Mesh::Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures)
{
    this->vertices = vertices;
    this->indices = indices;
    this->textures = textures;
    textureCount = textures.size();
}

Mesh::Mesh(vector<Vertex> vertices, vector<unsigned int> indices)
{
    this->vertices = vertices;
    this->indices = indices;
    this->textures.clear();
    textureCount = 0;
}

void Mesh::addTexture(vector<Texture> textures)
{
    for (int i = 0; i < textures.size(); i++)
    {
        this->textures.push_back(textures[i]);
        textureCount++;
    }
}
