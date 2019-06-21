#include "resource_manager.h"

ResourceManager::ResourceManager()//std::vector<std::string> shaderSourceFiles, std::vector<std::string> textureFiles)
{
    initShaders();
    initBuffers();
    initTextures();
}

void ResourceManager::initShaders()
{
    //tmp
    std::vector<std::string> shaderSourceFiles
    {
        "shader_src/vertex_shader.glsl",
        "shader_src/fragment_shader.glsl"
    };

    Shader s (shaderSourceFiles);
    shaderList.insert(std::pair<std::string, Shader*>("shader1", &s));
}

void ResourceManager::initVAO()
{
    //tmp
    std::vector<std::array<GLuint, 4>> vertexSettings
    {
        {0, 3, 8, 0},
        {1, 3, 8, 3},
        {2, 2, 8, 6}
    };

    VertexArrayObject vao(vertexSettings);
    vaoList.insert(std::pair<std::string, VertexArrayObject *> ("vao1", &vao));
}

void ResourceManager::initBuffers()
{
}

void ResourceManager::initTextures()
{
}

void ResourceManager::cleanup()
{
}

Shader ResourceManager::getShader(std::string shaderName)
{
    return *shaderList[shaderName];
}
