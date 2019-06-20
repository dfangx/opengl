#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "app.h"
#include "pong.h"

App::App(GLuint win_width, GLuint win_height, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
   this -> win_width = win_width;
   this -> win_height = win_height;

   this -> r = r;
   this -> g = g;
   this -> b = b;
   this -> a = a;

   createWindow();
   initGLEW();
}

App::~App()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void App::run()
{
    Pong pong;

    while (!glfwWindowShouldClose(window))
    {
        pong.processInput();

        glClearColor(r, g, b, a);
        glClear(GL_COLOR_BUFFER_BIT);
        
        pong.render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
};

void App::createWindow()
{
    // initializes glfw library
    if (!glfwInit()){
        std::cout << "ERROR: GLFW: initialization failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    // create a window and context
    window = glfwCreateWindow(win_width, win_height, "Simple Window", NULL, NULL);
    if (!window)
    {
        std::cout << "ERROR: GLFW: failed to create window" << std::endl;
        glfwTerminate();

        exit(EXIT_FAILURE);
    }

    // sets the current OpenGL context
    glfwMakeContextCurrent(window);
    // set framebuffer size callback function
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback); 
}

void App::initGLEW()
{
    glewExperimental = true; // prevents erros with opengl
    // initialize glew
    GLenum glewError = glewInit();
    if (glewError != GLEW_OK)
    {
        std::cout << "ERROR: GLEW: initialization failed. Error: " << glewGetErrorString(glewError) << std::endl;
        glfwTerminate();

        exit(EXIT_FAILURE);
    }

    // check if opengl 2.1 is supported
    if (!GLEW_VERSION_2_1)
    {
        std::cout << "ERROR: GLEW: OpenGl 2.1 not supported" << std::endl;
        glfwTerminate();

        exit(EXIT_FAILURE);
    }
}

void App::framebufferSizeCallback(GLFWwindow * window, int win_width, int win_height)
{
    glViewport(0, 0, win_width, win_height);
}
