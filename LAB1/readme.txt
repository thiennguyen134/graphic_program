Name: Thien Nguyen
Student id: AA7772
About project
1. Introduce my own data type for triangle vertices: I have defined a Vertex struct with position and color attributes:
struct Vertex {
    glm::vec3 position;
    glm::vec3 color;
};
2. Vertices should have a location (x, y, z) and a color (r, g, b): The Vertex struct has both position and color as required.

3. Convert vertices into a triangle with a red lower right corner, a green lower left corner, and a blue tip: I have created an array of vertices representing the triangle with the specified colors:
Vertex vertices[] = {
    {{1.0f, -1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}}, // Red lower right corner
    {{-1.0f, -1.0f, 0.0f}, {0.0f, 1.0f, 0.0f}}, // Green lower left corner
    {{0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}}  // Blue tip
};
4. Implement vertex and fragment shaders that draw a triangle on the screen: I have implemented the vertex shader (vertex_shader.glsl) and fragment shader (fragment_shader.glsl) that correctly pass the color attribute and draw the triangle on the screen.
5. Press the space bar to start rotating around the z-axis: I have implemented the key_callback function to toggle rotation when the space bar is pressed:
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        toggleRotation(rotationEnabled);
    }
}
6. Press the space bar again to stop the rotation of the triangle: The same key_callback function also stops the rotation when the space bar is pressed again.