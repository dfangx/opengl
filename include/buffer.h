#include <GL/glew.h>
#include <vector>
class Buffer
{
    public:
        Buffer(GLenum type, std::vector<GLfloat> data);
        void init();
        void setAttributePointer();

    private:
        GLuint bufferID;
        GLenum type;
        std::vector<GLfloat> data;

};
