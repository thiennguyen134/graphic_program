#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


struct Vertex {
    GLfloat position[3];
    GLfloat color[3];
};

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
std::string readFile(const std::string& filePath);
GLuint createShader(GLenum type, const std::string& source);
GLuint createProgram(GLuint vertexShader, GLuint fragmentShader);
void toggleRotation(bool& rotationEnabled);
