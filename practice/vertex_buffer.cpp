#include "vertex_buffer.h"
using namespace std;

VertexBuffer::VertexBuffer(vector<GLfloat> data)
{
    this -> data = data;
    glGenBuffers(1, &bufferID);
    bindBuffer();
    loadBuffer();
}

void VertexBuffer::loadBuffer()
{
    // copy data into currently bound buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), data.data(), GL_STATIC_DRAW);
}


void VertexBuffer::bindBuffer()
{
    //bind buffer to buffer type of ebo
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
}

