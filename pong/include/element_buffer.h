#ifndef ELEMENT_BUFFER_H
#define ELEMENT_BUFFER_H

#include "buffer.h"

class ElementBuffer:public Buffer
{
    public:
        ElementBuffer(std::vector<GLuint> data);
        void bindBuffer();
    private:
        void loadBuffer(std::vector<GLuint> data);
};
#endif
