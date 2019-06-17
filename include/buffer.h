#ifndef BUFFER_H
#define BUFFER_H
#include <GL/glew.h>
#include <vector>
class Buffer
{
    public:
        virtual void bindBuffer() = 0;

    //private:
    protected:
        GLuint bufferID;
        //GLenum type;
        //std::vector<GLfloat> data;

        virtual void loadBuffer() = 0;
};
#endif
