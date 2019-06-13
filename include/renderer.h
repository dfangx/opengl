class Renderer
{
    public:
        Renderer();
    private:
        std::vector<Shader> shaders;
        std::vector<Data> data;
        std::vector<Buffer> buffers;
        std::vector<GLuint> vao;
};
