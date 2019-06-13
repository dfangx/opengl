#include <iostream>
#include "buffer.h"

using namespace std;

Buffer::Buffer(GLenum type, vector<GLfloat> data)
{
    this -> type = type;
    this -> data = data;
}

void Buffer::init()
{
    cout << "BUFFER: creating buffer" << endl;
    glGenBuffers(1, &bufferID);

    //bind buffer to buffer type of ebo
    glBindBuffer(type, bufferID);

    // copy data into currently bound buffer
    glBufferData(type, sizeof(float) * data.size(), data.data(), GL_STATIC_DRAW);

}

void Buffer::setAttributePointer()
{
    cout << "BUFFER: setting attribute pointers" << endl;
    // how to interpret given vertex data
    // glVertexAttribPointer( vertex attrib location, size of vertex attrib, type of data, normalize, stride - space between consecutive attributes, offset )
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    // glEnableVertexAttribArray( location of vertex attrib )
    glEnableVertexAttribArray(0);
}
