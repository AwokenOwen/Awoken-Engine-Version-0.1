#include "MeshRenderer.h"
#include "WorldManager.h"
#include "WindowManager.h"
#include "ResourceManager.h"
#include "Scene.h"
#include "Camera.h"
#include <glad/glad.h>
#include "glm.hpp"
#include "gtc/type_ptr.hpp"
#include <iostream>

MeshRenderer::MeshRenderer(Object* _parent) : Component(_parent)
{
	mesh = nullptr;
    type = "MeshRenderer";
}

MeshRenderer::MeshRenderer(Object* _parent, Mesh* mesh) : Component(_parent)
{
	this->mesh = mesh;
    type = "MeshRenderer";
}

void MeshRenderer::OnEnable()
{
	if (mesh != nullptr)
	{
		setupMesh();
	}
}

void MeshRenderer::Update()
{
    if (mesh != nullptr)
    {
        Draw();
    }
}

void MeshRenderer::setupMesh()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, mesh->vertices.size() * sizeof(Mesh::Vertex), &mesh->vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->indices.size() * sizeof(unsigned int),
        &mesh->indices[0], GL_STATIC_DRAW);

    // vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Mesh::Vertex), (void*)0);
    // vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Mesh::Vertex), (void*)offsetof(Mesh::Vertex, normal));
    // vertex texture coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Mesh::Vertex), (void*)offsetof(Mesh::Vertex, texCoords));

    glBindVertexArray(0);
}

void MeshRenderer::Draw()
{
    // draw mesh
    unsigned int shaderProgram = World.getActiveScene()->getShaderProgram();

    glUseProgram(shaderProgram);

    for (int i = 0; i < mesh->textureCount; i++)
    {
        glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_2D, mesh->textures[i].id);
    }

    mat4 model = mat4(1.0f);
    mat4 projectionMatrix = Window.getProjectionMatrix();
    mat4 viewMatrix = World.getActiveScene()->getCamera()->getViewMatrix();


    model = projectionMatrix * viewMatrix * getParent()->worldModelMatrix();

    int modelLoc = glGetUniformLocation(shaderProgram, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, mesh->indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
