#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H
#include <string>
#include <vector>
#include <map>

#include "shader.h"
#include "vertex_array_object.h"

class ResourceManager
{
    public:
        ResourceManager();//std::vector<std::string> shaderSourceFiles, std::vector<std::string> textureFiles);
        Shader getShader(std::string shaderName);
        //Texture getTexture(std::string textureName);
    private:
        std::map<std::string, Shader * > shaderList;
        std::map<std::string, VertexArrayObject * > vaoList;
//        Texture * textureList;

        void initShaders();
        void initVAO();
        void initBuffers();
        void initTextures();
        void cleanup();

};
#endif
