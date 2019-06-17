#include "callback.h"

void framebuffer_size_callback(GLFWwindow * window, int win_width, int win_height)
{
    glViewport(0, 0, win_width, win_height);
}

void processInput(GLFWwindow * window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}
