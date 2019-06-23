#include <iostream>
#include "resource_manager.h"
#include "vertex_buffer.h"
#include "element_buffer.h"

ResourceManager::ResourceManager()//std::vector<std::string> shaderSourceFiles, std::vector<std::string> textureFiles)
{
    initShaders();
    initVAO();
    initTextures();
}

void ResourceManager::initShaders()
{
    Shader s (dS.getShaderSourceFiles());
    shaderList.insert(std::make_pair(dS.ShaderNames::BOXSHADER, &s));
}

void ResourceManager::initVAO()
{
    VertexArrayObject vao(dS.getVertexAttrib());
    initBuffers();
    vao.setAttributePointers();
    std::cout << "RESOURCE_MANAGER: registering VAO " << std::endl;
    vaoList.insert(std::make_pair(dS.VAONames::VAO_1, &vao));
    std::cout << "RESOURCE_MANAGER: done creating VAO" << std::endl;
}

void ResourceManager::initBuffers()
{
    VertexBuffer vB(dS.getVertices());
    ElementBuffer eB(dS.getIndices());
}

void ResourceManager::initTextures()
{
}

void ResourceManager::cleanup()
{
}

Shader * ResourceManager::getShader(GLenum shaderName)
{
    return shaderList[shaderName];
}

VertexArrayObject * ResourceManager::getVAO(GLenum vaoName)
{
    return vaoList[vaoName];
}
