#include <GL/glew.h>
#include <vector>

#include "shader.h"

class ShaderProgram
{
    public:
        ShaderProgram(std::vector<Shader> shaders);
        void init();
        GLuint getShaderProgramID();
    private:
        GLuint shaderProgramID;
        std::vector<Shader> shaders;
        void linkCheck();
};
