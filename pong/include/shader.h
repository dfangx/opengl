#ifndef SHADER_H
#define SHADER_H

//#include  <GL/glew.h>
#include <GL/glew.h>
#include <vector>
#include <string>

class Shader
{
    public:
        Shader(std::vector<std::string> shaderSourceFiles);

        void use();
        /*
        void setUniformFloat(std::string uniformName, GLfloat value);
        void setUniformInt(std::string uniformName, GLuint value);
        void setUniformMatrix(std::string uniformName, glm::mat4 value);
        */

    private:
        // Generated on shader creation
        GLuint shaderID;
        std::vector<GLuint> shaderStageIdList;

        void compileShader(std::vector<std::string> shaderSourceFiles);
        void linkShader();
        void deleteShaderStage();

        bool isCompiled(GLuint id);
        bool isLinked();

        std::string loadShaderSource(std::string fileName);
};
#endif
