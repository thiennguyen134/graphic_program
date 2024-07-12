#include "IApplication.h"
#include <GLFW/glfw3.h>

bool IApplication::IsKeyDown(uint16_t key) {
    GLFWwindow* window = glfwGetCurrentContext();
    return glfwGetKey(window, key) == GLFW_PRESS;
}
