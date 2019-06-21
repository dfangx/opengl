#include "buffer.h"

class ElementBuffer:public Buffer
{
    public:
        ElementBuffer(std::vector<GLuint> data);
        void bindBuffer();
    private:
        std::vector<GLuint> data;
        void loadBuffer();
};
