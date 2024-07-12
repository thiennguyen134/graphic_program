// Geometry.cpp
#include "Geometry.h"
#include <stdexcept>

Geometry::Geometry() : VAO(0), VBO(0) {}

Geometry::Geometry(float width, float height, float depth) : VAO(0), VBO(0) {
    float w = width / 2.0f;
    float h = height / 2.0f;
    float d = depth / 2.0f;

    std::vector<float> vertices = {
        // Front face
        -w, -h,  d,  w, -h,  d,  w,  h,  d,
         w,  h,  d, -w,  h,  d, -w, -h,  d,
         // Back face
         -w, -h, -d, -w,  h, -d,  w,  h, -d,
          w,  h, -d,  w, -h, -d, -w, -h, -d,
          // Left face
          -w, -h,  d, -w,  h,  d, -w,  h, -d,
          -w,  h, -d, -w, -h, -d, -w, -h,  d,
          // Right face
           w, -h,  d,  w, -h, -d,  w,  h, -d,
           w,  h, -d,  w,  h,  d,  w, -h,  d,
           // Top face
           -w,  h,  d,  w,  h,  d,  w,  h, -d,
            w,  h, -d, -w,  h, -d, -w,  h,  d,
            // Bottom face
            -w, -h,  d, -w, -h, -d,  w, -h, -d,
             w, -h, -d,  w, -h,  d, -w, -h,  d
    };

    setupBuffers(vertices);
}

Geometry::Geometry(const std::vector<float>& vertices) : VAO(0), VBO(0) {
    setupBuffers(vertices);
}

Geometry::~Geometry() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Geometry::draw() const {
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}

void Geometry::setupBuffers(const std::vector<float>& vertices) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    if (VAO == 0 || VBO == 0) {
        throw std::runtime_error("Failed to create buffer objects");
    }

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
