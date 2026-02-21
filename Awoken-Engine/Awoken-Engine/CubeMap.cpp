#include "CubeMap.h"
#include "Material.h"
#include "WorldManager.h"
#include "WindowManager.h"
#include "Camera.h"
#include "ResourceManager.h"

#include "glad/glad.h"
#include "glm.hpp"
#include <gtc/type_ptr.hpp>

CubeMap::CubeMap(vector<const char*> paths, float size) : Mesh(vertices, indices)
{
	vector<Mesh::Vertex> vertices =
	{
		Mesh::Vertex(vec3(-0.5, 0.5, 0.5) * size),
		Mesh::Vertex(vec3(-0.5, -0.5, 0.5) * size),
		Mesh::Vertex(vec3(0.5, -0.5, 0.5) * size),
		Mesh::Vertex(vec3(0.5, 0.5, 0.5) * size),
		Mesh::Vertex(vec3(-0.5, 0.5, -0.5) * size),
		Mesh::Vertex(vec3(-0.5, -0.5, -0.5) * size),
		Mesh::Vertex(vec3(0.5, -0.5, -0.5) * size),
		Mesh::Vertex(vec3(0.5, 0.5, -0.5) * size),
	};
	vector<unsigned int> indices =
	{
		0, 1, 3,
		0, 2, 3,
		4, 5, 7,
		4, 6, 7,
		0, 4, 6,
		0, 2, 6,
		1, 5, 7,
		1, 3, 7,
		2, 6, 7,
		2, 3, 7,
		0, 4, 5,
		0, 1, 5
	};

	material = new Material("assets/defaultAssets/cubeMap.vert", "assets/defaultAssets/cubeMap.frag");
	material->type = MaterialType::CUBEMAP;

	material->setCubeMapTexture(paths);
}

void CubeMap::Draw()
{
	//cout << "haha you dumb" << endl;

	// draw mesh
	unsigned int shaderProgram = material->getShaderProgram();

	glUseProgram(shaderProgram);

	glm::mat4 view = glm::mat4(glm::mat3(World.getActiveScene()->getCamera()->getViewMatrix()));
	glm::mat4 projection = Window.getPerspectiveMatrix();

	int viewLoc = glGetUniformLocation(shaderProgram, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	int projectionLoc = glGetUniformLocation(shaderProgram, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

	// Load Textures
	material->loadTextures();

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}
