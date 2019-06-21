#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "app.h"
#include "callback.h"
#include "vertex_buffer.h"
#include "element_buffer.h"
#include "shader.h"
#include "vertex_array_object.h"
#include "texture.h"

using namespace std;
using namespace glm;

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

    vector<array<GLuint, 3>> settings 
    {
        {GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT},
        {GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT},
        {GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR},
        {GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR},
    };

    string fileNames[2] = {"shaders/vertex2.glsl", "shaders/fragment2.glsl"};

    vector<GLfloat> data
    {
        // positions      colors            texture coordinates 
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f
    };

    vector<GLuint> indices
    {
        0, 1, 3,
        1, 2, 3,
    };

    vector<array<GLuint, 4>> vertexSettings
    {
        {0, 3, 8, 0},
        {1, 3, 8, 3},
        {2, 2, 8, 6}
    };

    Texture texture1("textures/container.jpg", settings, GL_RGB);
    Texture texture2("textures/awesomeface.png", settings, GL_RGBA);
    Shader s(fileNames);
    VertexArrayObject vao(vertexSettings);
    VertexBuffer vbuffer(data);
    ElementBuffer ebuffer(indices);

    vao.setAttributePointers();

    s.use();
    s.setUniformInt("texture1", 0);
    s.setUniformInt("texture2", 1);

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);
        glClearColor(r, g, b, a);
        glClear(GL_COLOR_BUFFER_BIT);
        glActiveTexture(GL_TEXTURE0);
        texture1.bindTexture();
        glActiveTexture(GL_TEXTURE1);
        texture2.bindTexture();
        s.use();
        mat4 trans = mat4(1.0f);
        trans = rotate(trans, (float)glfwGetTime(), vec3(0.0f, 0.0f, 1.0f));
        trans = translate(trans, vec3(0.5f, -0.5f, 0.0f));
        s.setUniformMatrix("transform", trans);
        vao.bindVAO();
        //glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        mat4 trans2 = mat4(1.0);
        trans2 = translate(trans2, vec3(-0.5f, 0.5f, 0.0f));
        trans2 = scale(trans2, vec3(sin((float)glfwGetTime()), sin((float)glfwGetTime()), sin((float)glfwGetTime())));
        s.setUniformMatrix("transform", trans2);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
};

void App::createWindow()
{
    // initializes glfw library
    if (!glfwInit()){
        cout << "ERROR: GLFW: initialization failed" << endl;
        exit(EXIT_FAILURE);
    }

    // create a window and context
    window = glfwCreateWindow(win_width, win_height, "Simple Window", NULL, NULL);
    if (!window)
    {
        cout << "ERROR: GLFW: failed to create window" << endl;
        glfwTerminate();

        exit(EXIT_FAILURE);
    }

    // sets the current OpenGL context
    glfwMakeContextCurrent(window);
    // set framebuffer size callback function
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void App::initGLEW()
{
    glewExperimental = true; // prevents erros with opengl
    // initialize glew
    GLenum glewError = glewInit();
    if (glewError != GLEW_OK)
    {
        cout << "ERROR: GLEW: initialization failed. Error: " << glewGetErrorString(glewError) << endl;
        glfwTerminate();

        exit(EXIT_FAILURE);
    }

    // check if opengl 2.1 is supported
    if (!GLEW_VERSION_2_1)
    {
        cout << "ERROR: GLEW: OpenGl 2.1 not supported" << endl;
        glfwTerminate();

        exit(EXIT_FAILURE);
    }
}
