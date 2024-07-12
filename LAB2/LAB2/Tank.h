
#pragma once

#include "Geometry.h"
#include "Shader.h"
#include <glm/glm.hpp>

#pragma once

#include "Geometry.h"
#include "Shader.h"
#include <glm/glm.hpp>

class Tank {
public:
    Tank();

    void draw(const Shader& shader) const;
    void update(float deltaTime);

    void processInput(GLFWwindow* window, float deltaTime);


private:
    Geometry body;
    Geometry turret;
    Geometry gun;

    glm::vec3 position;
    float bodyRotation;
    float turretRotation;
    float gunRotation;
};
