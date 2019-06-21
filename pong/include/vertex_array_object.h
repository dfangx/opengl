#include <GL/glew.h>
#include <vector>
#include <array>

class VertexArrayObject
{
    public:
        VertexArrayObject(std::vector<std::array<GLuint, 4>> settings);
        void bindVAO();
        void setAttributePointers();

    private:
        GLuint vaoID;
        std::vector<std::array<GLuint, 4>> settings; // location, dimension, stride, offset
};
