#include "Mesh.h"
#include "Material.h"
#include "glad/glad.h"
#include "WorldManager.h"
#include "WindowManager.h"
#include "Camera.h"
#include "Object.h"
#include "DirectionalLight.h"
#include <gtc/type_ptr.hpp>
#include "MeshRenderer.h"


Mesh::Mesh(vector<Vertex> vertices, vector<unsigned int> indices)
{
    this->vertices = vertices;
    this->indices = indices;

    setupMesh();
}

void Mesh::setupMesh()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Mesh::Vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),
        &indices[0], GL_STATIC_DRAW);

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

void Mesh::setUpShaderVariables(unsigned int shaderProgram)
{
    //// Ambient Light
    //vec3 ambientLight = World.getActiveScene()->ambientLight;

    //int ambientLoc = glGetUniformLocation(shaderProgram, "ambientStrength");
    //glUniform3f(ambientLoc, ambientLight.x, ambientLight.y, ambientLight.z);

    vec3 cameraPosition = World.getActiveScene()->getCamera()->GetWorldPosition();

    int cameraLoc = glGetUniformLocation(shaderProgram, "camPos");
    glUniform3f(cameraLoc, cameraPosition.x, cameraPosition.y, cameraPosition.z);

    setUpDirectionalLight(shaderProgram);
    setUpPointLights(shaderProgram);
}

void Mesh::setUpDirectionalLight(unsigned int shaderProgram)
{
    // Directional Light
    vec3 direction = -World.getActiveScene()->directionalLight->getDirection();
    float power = World.getActiveScene()->directionalLight->getPower();
    vec3 color = World.getActiveScene()->directionalLight->getColor();

    int directionLoc = glGetUniformLocation(shaderProgram, "dirLightDir");
    glUniform3f(directionLoc, direction.x, direction.y, direction.z);

    //int powerLoc = glGetUniformLocation(shaderProgram, "directionalLight.power");
    //glUniform1f(powerLoc, power);

    int colorLoc = glGetUniformLocation(shaderProgram, "dirLightColor");
    glUniform3f(colorLoc, color.x, color.y, color.z);
}

void Mesh::setUpPointLights(unsigned int shaderProgram)
{
    //just test for now 
}

void Mesh::Draw()
{
    // draw mesh
    unsigned int shaderProgram = material->getShaderProgram();

    glUseProgram(shaderProgram);

    material->loadTextures();

    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Vertex Matrix Stuff
    mat4 model = mat4(1.0f);
    mat4 projectionMatrix = Window.getProjectionMatrix();
    mat4 viewMatrix = World.getActiveScene()->getCamera()->getViewMatrix();

    model = projectionMatrix * viewMatrix * getParent()->worldModelMatrix();

    int fullModelLoc = glGetUniformLocation(shaderProgram, "modelViewProjection");
    glUniformMatrix4fv(fullModelLoc, 1, GL_FALSE, glm::value_ptr(model));

    int modelLoc = glGetUniformLocation(shaderProgram, "modelView");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(getParent()->worldModelMatrix() * viewMatrix));

    setUpShaderVariables(shaderProgram);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

Object* Mesh::getParent() 
{
    return parent;
}

void Mesh::setParent(Object* parent) 
{
    this->parent = parent;
}