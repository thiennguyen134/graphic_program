#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Geometry {
public:
    Geometry(float width, float height, float depth);
    Geometry();
    Geometry(const std::vector<float>& vertices);
    ~Geometry(); 

    void draw() const;

private:
    GLuint VAO;
    GLuint VBO;

    void setupBuffers(const std::vector<float>& vertices);
};
