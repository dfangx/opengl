#include <GL/glew.h>
#include <iostream>

using namespace std;

void querySpecs()
{
    // Query OpenGL Version
    const GLubyte * glVersion = glGetString(GL_VERSION);
    cout << "OpenGL Version: " << glVersion << "\n";

    // Query OpenGL Shading Language
    const GLubyte * glSL = glGetString(GL_SHADING_LANGUAGE_VERSION);
    cout << "OpenGL Shader Language Version: " << glSL << "\n";

    // Check for specific functionality provided by GLEW
    if (GLEW_ARB_vertex_array_object)
    {
        cout << "genVertexArrays supported. \n";
    }
    if (GLEW_APPLE_vertex_array_object)
    {
        cout << "genVertexArrayAPPLE supported \n";
    }
}
