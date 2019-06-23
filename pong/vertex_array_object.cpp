#include <iostream>
#include "vertex_array_object.h"

VertexArrayObject::VertexArrayObject(std::vector<std::array<GLuint, 4>> settings)
{
    this -> settings = settings;
    glGenVertexArrays(1, &vaoID);

    bindVAO();
}

void VertexArrayObject::bindVAO()
{
    glBindVertexArray(vaoID);
}

void VertexArrayObject::setAttributePointers()
{
    // how to interpret given vertex data
    // glVertexAttribPointer( vertex attrib location, size of vertex attrib, type of data, normalize, stride - space between consecutive attributes, offset )
    for (std::vector<std::array<GLuint, 4>>::iterator i = settings.begin(); i != settings.end(); i++)
    {
        std::cout << (*i)[0] << (*i)[1] << (*i)[2] << (*i)[3] << std::endl;
        glVertexAttribPointer((*i)[0], (*i)[1], GL_FLOAT, GL_FALSE, (*i)[2] * sizeof(float), (void*)((*i)[3] * sizeof(float)));
        // glEnableVertexAttribArray( location of vertex attrib )
        glEnableVertexAttribArray((*i)[0]);
    }
}
