#pragma once
#include <vector>
#include <string>
#include "glm.hpp"

using namespace glm;
using namespace std;

class Mesh
{
public:
	struct Vertex
	{
		vec3 position;
		vec3 normal;
		vec2 texCoords;

		Vertex(vec3 position, vec3 normal, vec2 texCoords) {
			this->position = position;
			this->normal = normal;
			this->texCoords = texCoords;
		}
	};

	struct Texture {
		unsigned int id = 0;
		string type;

		Texture(unsigned int id, string type) {
			this->id = id;
			this->type = type;
		}
	};

	// mesh data
	vector<Vertex>       vertices;
	vector<unsigned int> indices;
	vector<Texture>      textures;

	int textureCount = 0;

	Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
	Mesh(vector<Vertex> vertices, vector<unsigned int> indices);

	void addTexture(vector<Texture> textures);
};

