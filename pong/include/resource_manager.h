#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H
#include <string>
#include <vector>
#include <map>

#include "shader.h"
#include "vertex_array_object.h"
#include "data_storage.h"

class ResourceManager
{
    public:
        ResourceManager();//std::vector<std::string> shaderSourceFiles, std::vector<std::string> textureFiles);
        Shader* getShader(GLenum shaderName);
        VertexArrayObject* getVAO(GLenum vaoName);
        //Texture getTexture(std::string textureName);
    private:
        DataStorage dS;
        std::map<GLenum, Shader*> shaderList;
        std::map<GLenum, VertexArrayObject*> vaoList;
//        Texture * textureList;

        void initShaders();
        void initVAO();
        void initBuffers();
        void initTextures();
        void cleanup();

};
#endif
