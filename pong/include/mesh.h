#include <vector>

#include "utils.h"

class Mesh
{
    public:
        Mesh(vector<Vertex> vertices, vector<GLuint> indices);
        void draw();
    private:

        vector<Vertex> vertices;
        vector<GLuint> indices;
};
