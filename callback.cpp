#include <GLFW/glfw3.h>
void framebuffer_size_callback(GLFWwindow * window, int win_width, int win_height)
{
    glViewport(0, 0, win_width, win_height);
}
