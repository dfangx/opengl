#include "buffer.h"
class VertexBuffer:public Buffer
{
    public:
        VertexBuffer(std::vector<GLfloat> data);
        void bindBuffer();
    private:
        std::vector<GLfloat> data;
        void loadBuffer();
};
