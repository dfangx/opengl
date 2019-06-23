#include "element_buffer.h"

ElementBuffer::ElementBuffer(std::vector<GLuint> indices)
{
    glGenBuffers(1, &bufferID);
    bindBuffer();
    loadBuffer(indices);
}

void ElementBuffer::loadBuffer(std::vector<GLuint> indices)
{
    // copy data into currently bound buffer
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), indices.data(), GL_STATIC_DRAW);
}


void ElementBuffer::bindBuffer()
{
    //bind buffer to buffer type of ebo
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
}


