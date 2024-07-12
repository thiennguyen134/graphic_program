#include "Tank.h"
#include <glm/gtc/matrix_transform.hpp> 
#include "Tank.h"
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

Tank::Tank()
    : position(0.0f, 0.0f, 0.0f),
    bodyRotation(0.0f),
    turretRotation(0.0f),
    gunRotation(0.0f),
    body(2.0f, 1.0f, 3.0f),
    turret(1.5f, 0.5f, 2.0f),
    gun(0.5f, 0.5f, 2.0f) {}

void Tank::draw(const Shader& shader) const {
    glm::mat4 modelMatrix;

 
    modelMatrix = glm::translate(glm::mat4(1.0f), position);
    modelMatrix = glm::rotate(modelMatrix, glm::radians(bodyRotation), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", modelMatrix);
    body.draw();

  
    modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 1.0f, 0.0f));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(turretRotation), glm::vec3(0.0f, 1.0f, 0.0f));
    shader.setMat4("model", modelMatrix);
    turret.draw();

    modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.5f, 1.0f));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(gunRotation), glm::vec3(1.0f, 0.0f, 0.0f));
    shader.setMat4("model", modelMatrix);
    gun.draw();
}

void Tank::update(float deltaTime) {
    
}

void Tank::processInput(GLFWwindow* window, float deltaTime) {
    const float rotationSpeed = 50.0f;
    const float movementSpeed = 2.0f;

 
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        bodyRotation += rotationSpeed * deltaTime;
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        bodyRotation -= rotationSpeed * deltaTime;
    }
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        position.x -= movementSpeed * deltaTime * sin(glm::radians(bodyRotation));
        position.z -= movementSpeed * deltaTime * cos(glm::radians(bodyRotation));
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        position.x += movementSpeed * deltaTime * sin(glm::radians(bodyRotation));
        position.z += movementSpeed * deltaTime * cos(glm::radians(bodyRotation));
    }

    
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        turretRotation += rotationSpeed * deltaTime;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        turretRotation -= rotationSpeed * deltaTime;
    }

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        gunRotation += rotationSpeed * deltaTime;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        gunRotation -= rotationSpeed * deltaTime;
    }
}

