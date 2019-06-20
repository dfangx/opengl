#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H
#include <string>
#include <vector>

#include "shader.h"

class ResourceManager
{
    public:
        ResourceManager(std::vector<std::string> shaderSourceFiles, std::vector<std::string> textureFiles);
    private:
        std::vector<Shader>shaderList;
//        Texture * textureList;

        void initShaders();
        void initTextures();
        void cleanup();
};
#endif
