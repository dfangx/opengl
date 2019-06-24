#include <GL/glew.h>

#include <vector>
#include <array>

class DataStorage
{
    public:
        enum ShaderNames
        {
            BOXSHADER
        };

        enum VAONames
        {
            VAO_1
        };

        DataStorage();
        std::vector<std::string> getShaderSourceFiles(); 
        std::vector<std::array<GLuint, 4>> getVertexAttrib();
        std::vector<GLfloat> getVertices();
        std::vector<GLuint> getIndices();

    private:

        std::vector<std::string> shaderSourceFiles;
        std::vector<std::array<GLuint, 4>> vertexAttrib;
        std::vector<GLfloat> vertices;
        std::vector<GLuint> indices;
};
