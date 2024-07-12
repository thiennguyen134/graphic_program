#pragma once

#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>

class Shader {
public:
    Shader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
    ~Shader();

    void use() const;
    void setMat4(const std::string& name, const glm::mat4& mat) const;

private:
    GLuint ID;

    GLuint compileShader(const std::string& shaderSource, GLenum shaderType) const;
};
