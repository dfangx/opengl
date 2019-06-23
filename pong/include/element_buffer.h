#ifndef ELEMENT_BUFFER_H
#define ELEMENT_BUFFER_H

#include "buffer.h"

class ElementBuffer:public Buffer
{
    public:
        ElementBuffer(std::vector<GLuint> indices);
        void bindBuffer();
    private:
        void loadBuffer(std::vector<GLuint> indices);
};
#endif
