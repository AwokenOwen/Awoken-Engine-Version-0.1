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

	// Load Texture from path
	void setAlbedoTexture(const char* path, int type = 0);
	void setNormalTexture(const char* path, int type = 0);
	void setMetallicTexture(const char* path, int type = 0);
	void setRoughnessTexture(const char* path, int type = 0);
	void setAmbientOcclusionTexture(const char* path, int type = 0);
	void setEmissionTexture(const char* path, int type = 0);
	void setOpacityTexture(const char* path, int type = 0);

	// Load already loaded texture
	void setAlbedoTexture(unsigned int id);
	void setNormalTexture(unsigned int id);
	void setMetallicTexture(unsigned int id);
	void setRoughnessTexture(unsigned int id);
	void setAmbientOcclusionTexture(unsigned int id);
	void setEmissionTexture(unsigned int id);
	void setOpacityTexture(unsigned int id, int type = 0);

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
	// Opacity Texture
	unsigned int opacityTexture;

	// Shader Program
	unsigned int shaderProgram;

	void loadBaseTextures();
};

