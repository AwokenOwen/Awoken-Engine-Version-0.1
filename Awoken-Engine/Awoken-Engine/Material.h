#pragma once
#include "glm.hpp"
#include <vector>

using namespace glm;
using namespace std;

class Material
{
public:
	Material();

	Material(const char* vertexShaderPath, const char* fragmentShaderPath);

	void setShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath);
	unsigned int getShaderProgram();

	void loadTextures();

	void setAlbedoTexture(const char* path, int type = 0);
	void setMetallicTexture(const char* path, int type = 0);
	void setRoughnessTexture(const char* path, int type = 0);
	void setNormalTexture(const char* path, int type = 0);
	void setAmbientOcclusionTexture(const char* path, int type = 0);
	void setEmissionTexture(const char* path, int type = 0);

	vector<unsigned int> extraTextures;

private:

	// Material Attributes
	// Base Color
	unsigned int albedoTexture;
	// Normal
	unsigned int normalTexture;
	// Metallic
	unsigned int metallicTexture;
	// Roughness
	unsigned int roughnessTexture;
	// Ambient Occlusion
	unsigned int ambientOcclusionTexture;
	// Emission Texture
	unsigned int emissionTexture;

	// Shader Program
	unsigned int shaderProgram;

	void loadBaseTextures();
};

