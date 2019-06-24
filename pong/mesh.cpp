#include "mesh.h"

Mesh::Mesh(vector<Vertex> vertices, vector<GLuint> indices)
{
    this -> vertices = vertices;
    this -> indices = indices;
}

void Mesh::Mesh draw()
{
}
