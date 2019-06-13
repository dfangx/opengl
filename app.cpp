#include <iostream>

#include "app.h"
#include "callback.h"
#include "buffer.h"
#include "shader.h"
#include "vertex_array_object.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace std;

App::App(GLuint win_width, GLuint win_height, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
   this -> win_width = win_width;
   this -> win_height = win_height;

   this -> r = r;
   this -> g = g;
   this -> b = b;
   this -> a = a;
}

App::~App()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void App::run()
{
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // texture filtering options
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    GLuint width, height, numChannels;
    // width, height, number of color channels
    unsigned char * texData = stbi_load("textures/container.jpg", &width, &height, &numChannels, 0);
    if (!data)
    {
        cout << "TEXTURE: failed to load texture" << endl;
        exit(EXIT_FAILURE);
    }
    // texture target, mipmap level, format, width, height, 0, format of source, datatype of source, data
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texData);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);

    string fileNames[2] = {"shaders/vertex2.glsl", "shaders/fragment2.glsl"};

    Shader s(fileNames);

    vector<GLfloat> data
    {
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
    };

    VertexArrayObject vao;
    vao.bindVAO();
    Buffer buffer(GL_ARRAY_BUFFER, data);
    buffer.init();
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    //buffer.setAttributePointer();

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(r, g, b, a);
        glClear(GL_COLOR_BUFFER_BIT);
        s.use();
        vao.bindVAO();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
};

void App::draw(GLuint vao)
{
}

void App::init()
{
    cout << "APP: creating window..." << endl;
    createWindow();
    cout << "APP: initializing GLEW" << endl;
    initGLEW();
    cout << "APP: initialization complete" << endl;

}

void App::createWindow()
{
    // initializes glfw library
    if (!glfwInit()){
        cout << "GLFW: initialization failed \n";
        exit(EXIT_FAILURE);
    }

    
    // create a window and context
    window = glfwCreateWindow(win_width, win_height, "Simple Window", NULL, NULL);
    if (!window)
    {
        cout << "GLFW: failed to create window \n";
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
        cout << "GLEW: initialization failed. Error: " << glewGetErrorString(glewError) << "\n";
        exit(EXIT_FAILURE);
    }

    // check if opengl 2.1 is supported
    if (!GLEW_VERSION_2_1)
    {
        cout << "GLEW: OpenGl 2.1 not supported.\n";
        exit(EXIT_FAILURE);
    }
}
