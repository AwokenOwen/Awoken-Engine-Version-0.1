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
	};

	struct Texture {
		unsigned int id;
		string type;
	};

	// mesh data
	vector<Vertex>       vertices;
	vector<unsigned int> indices;
	vector<Texture>      textures;

	Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
};

