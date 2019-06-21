#include <GL/glew.h>
#include <vector>
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
    public:
        Shader(std::string * shaderSourceFiles, GLuint * shaderStages = NULL);

        void use();
        void setUniformFloat(std::string uniformName, GLfloat value);
        void setUniformInt(std::string uniformName, GLuint value);
        void setUniformMatrix(std::string uniformName, glm::mat4 value);

    private:
        // Generated on shader creation
        GLuint shaderID;
        std::vector<GLuint> shaderStageID;  // List of shader stage ids to use for this shader program
        GLuint numShaderStages;

        // Provided by the user
        GLuint * shaderStages;      // List of shader stages to use for this shader
        std::string * shaderSourceFiles; // List of shader source code to use for this shader program

        // Stage number indicators
        const GLuint SHADER_STAGE_COMPILE;
        const GLuint SHADER_LINK;

        void createShader();
        void link();
        void shaderChecks(GLuint id, GLuint step);
        void deleteShaderStage();

        std::string readShaderSource(std::string fileName);
};
