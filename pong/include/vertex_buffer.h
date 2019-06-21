#ifndef VErTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include "buffer.h"
class VertexBuffer:public Buffer
{
    public:
        VertexBuffer(std::vector<GLfloat> data);
        void bindBuffer();
    private:
        void loadBuffer(std::vector<GLfloat> data);
};
#endif
