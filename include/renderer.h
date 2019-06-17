class Renderer
{
    public:
        Renderer();
        void draw();
    private:
        std::vector<Shader*> shaders;
        std::vector<Data*> data;
        std::vector<Buffer*> buffers;
        std::vector<GLuint*> vao;
};
