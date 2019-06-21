#include <GL/glew.h>
#include <vector>
#include <string>
#include <array>

class Texture
{
    public:
        Texture(std::string textureFile, std::vector<std::array<GLuint, 3>> textureSettings, GLuint colorFormat);
        void bindTexture();
    private:
        GLuint textureID;
        GLint width;
        GLint height;
        GLint numColorChannels;
        std::string textureFile;
        std::vector<std::array<GLuint, 3>> textureSettings;
        unsigned char * textureData;

        void loadTexture();
        void setParameters();
};
