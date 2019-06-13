#include "vertex_array_object.h"

VertexArrayObject::VertexArrayObject()
{
    glGenVertexArrays(1, &vaoID);
}

void VertexArrayObject::bindVAO()
{
    glBindVertexArray(vaoID);
}
