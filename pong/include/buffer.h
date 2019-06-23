#ifndef BUFFER_H
#define BUFFER_H

#include <GL/glew.h>
#include <vector>
class Buffer
{
    public:
        virtual void bindBuffer() = 0;

    protected:
        GLuint bufferID;

        virtual void loadBuffer(std::vector<GLfloat> data){};
        virtual void loadBuffer(std::vector<GLuint> indices){};
};
#endif

