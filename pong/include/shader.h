#ifndef SHADER_H
#define SHADER_H

//#include  <GL/glew.h>
#include <GL/glew.h>
#include <vector>
#include <string>

class Shader
{
    public:
        Shader();

        void use();
        /*
        void setUniformFloat(std::string uniformName, GLfloat value);
        void setUniformInt(std::string uniformName, GLuint value);
        void setUniformMatrix(std::string uniformName, glm::mat4 value);
        */

    private:
        enum class ShaderNames
        {
            VERTEX_SHADER,
            FRAGMENT_SHADER,
            NUM_SHADERS 
        };

        // Generated on shader creation
        GLuint shaderID;
        std::vector<GLuint> shaderStageIdList;

        // Provided by the user
        GLuint * shaderStages;      // List of shader stages to use for this shader
        std::string * shaderSourceFiles; // List of shader source code to use for this shader program

        std::string loadShaderSource(std::string fileName);
        void compileShader();
        void linkShader();
        void deleteShaderStage();
        void createShader();

        bool isCompiled(GLuint id);
        bool isLinked();
};
#endif
