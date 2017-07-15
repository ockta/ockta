#include <iostream>

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>

int main(int argc, char** argv) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    auto window = glfwCreateWindow(1280, 800, "OpenGl", nullptr, nullptr);

    if (!window) {
        std::cout << "Failed to create OpenGL context" << std::endl;
        return 1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGL();
    std::cout << "OpenGl: " << glGetString(GL_VERSION) << std::endl;

    while (!glfwWindowShouldClose(window)) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }

        glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
