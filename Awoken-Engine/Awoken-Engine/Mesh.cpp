#include "Mesh.h"

Mesh::Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures)
{
    this->vertices = vertices;
    this->indices = indices;
    this->textures = textures;
}

Mesh::Mesh(vector<Vertex> vertices, vector<unsigned int> indices)
{
    this->vertices = vertices;
    this->indices = indices;
    this->textures.clear();
}
