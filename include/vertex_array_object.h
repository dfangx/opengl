#include <GL/glew.h>
class VertexArrayObject
{
    public:
        VertexArrayObject();
        void bindVAO();
    private:
        GLuint vaoID;

};
