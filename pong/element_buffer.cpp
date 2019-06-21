#include "element_buffer.h"

ElementBuffer::ElementBuffer(std::vector<GLuint> data)
{
    glGenBuffers(1, &bufferID);
    bindBuffer();
    loadBuffer(data);
}

void ElementBuffer::loadBuffer(std::vector<GLuint> data)
{
    // copy data into currently bound buffer
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * data.size(), data.data(), GL_STATIC_DRAW);
}


void ElementBuffer::bindBuffer()
{
    //bind buffer to buffer type of ebo
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
}


