#include "vertex_buffer.h"

VertexBuffer::VertexBuffer(std::vector<GLfloat> data)
{
    glGenBuffers(1, &bufferID);
    bindBuffer();
    loadBuffer(data);
}

void VertexBuffer::loadBuffer(std::vector<GLfloat> data)
{
    // copy data into currently bound buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), data.data(), GL_STATIC_DRAW);
}


void VertexBuffer::bindBuffer()
{
    //bind buffer to buffer type of ebo
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
}

