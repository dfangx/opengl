#include "data_storage.h"

DataStorage::DataStorage()
{
    shaderSourceFiles =
    {
        "shader_src/vertex_shader.glsl",
        "shader_src/fragment_shader.glsl"
    };

    vertexAttrib =
    {
        {0, 3, 3, 0},
//        {1, 3, 6, 3},
    };

    vertices =
    {
        // positions      colors            
        0.25f, -0.95f, 0.0f,// 1.0f, 0.0f, 0.0f, 
        0.25f, -1.0f, 0.0f,// 0.0f, 1.0f, 0.0f,
        -0.25f, -1.0, 0.0f,// 0.0f, 0.0f, 1.0f
        -0.25f, -0.95f, 0.0f,// 1.0f, 1.0f, 0.0f,
    };

    indices =
    {
        0, 1, 3,
        1, 2, 3,
    };
}

std::vector<std::string> DataStorage::getShaderSourceFiles()
{
    return shaderSourceFiles;
}

std::vector<std::array<GLuint, 4>> DataStorage::getVertexAttrib()
{
    return vertexAttrib;
}

std::vector<GLfloat> DataStorage::getVertices()
{
    return vertices;
}

std::vector<GLuint> DataStorage::getIndices()
{
    return indices;
}
