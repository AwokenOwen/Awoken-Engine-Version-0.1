#pragma once
#include "glm.hpp"
#include <vector>

using namespace glm;
using namespace std;

enum MaterialType
{
	DEFAULT_LIT,
	CUBEMAP
};

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

	void setCubeMapTexture(vector<const char*> paths);

	vector<unsigned int> extraTextures;

	MaterialType type;

	bool twoSided;

private:

	void loadDefaultLitTextures();

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

	unsigned int cubeMapTexture;

	// Shader Program
	unsigned int shaderProgram;
};

