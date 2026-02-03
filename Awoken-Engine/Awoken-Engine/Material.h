#pragma once
#include "glm.hpp"

using namespace glm;

class Material
{
public:
	Material();



private:

	// Material Attributes

	// Base Color
	unsigned int baseColorTexture;

	// Metallic
	unsigned int metallicTexture;

	// Specular
	unsigned int specularTexture;

	// Roughness
	unsigned int roughnessTexture;

	// Ambient Occlusion
	unsigned int ambientOcclusionTexture;

	// Opacity
	unsigned int opacityTexture;

	// World Position Offset
	unsigned int WPOTexture;
};

