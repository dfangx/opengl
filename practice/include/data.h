class Data
{
    public:
        virtual void draw() = 0;
        std::vector<GLfloat> getVertices();
    protected:
        std::vector<GLfloat> vertices;
        GLfloat r, g, b, a;
}
