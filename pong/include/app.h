#ifndef APP_H
#define APP_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class App
{
    public:
        App(GLuint win_width, GLuint win_height, GLfloat r = 1, GLfloat g = 1, GLfloat b = 1, GLfloat a = 1);
        ~App();

        void run();

    private:
        GLuint win_height, win_width;
        GLfloat r, g, b, a;
        GLFWwindow * window;

        void createWindow();
        void initGLEW();
        static void framebufferSizeCallback(GLFWwindow * window, int win_width, int win_height);

};
#endif
