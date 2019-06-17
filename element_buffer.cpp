#include "element_buffer.h"
using namespace std;

ElementBuffer::ElementBuffer(vector<GLuint> data)
{
    this -> data = data;
    glGenBuffers(1, &bufferID);
    bindBuffer();
    loadBuffer();
}

void ElementBuffer::loadBuffer()
{
    // copy data into currently bound buffer
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * data.size(), data.data(), GL_STATIC_DRAW);
}


void ElementBuffer::bindBuffer()
{
    //bind buffer to buffer type of ebo
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
}


