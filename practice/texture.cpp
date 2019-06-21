#include <iostream>

#include "texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace std;

Texture::Texture(string textureFile, vector<array<GLuint, 3>> textureSettings, GLuint colorFormat)
{
    this -> textureSettings = textureSettings;
    this -> textureFile = textureFile;

    glGenTextures(1, &textureID);
    bindTexture();
    setParameters();
    stbi_set_flip_vertically_on_load(true);
    loadTexture();
    glTexImage2D(GL_TEXTURE_2D, 0, colorFormat, width, height, 0, colorFormat, GL_UNSIGNED_BYTE, textureData);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(textureData);
}

void Texture::loadTexture()
{
    textureData = stbi_load(textureFile.c_str(), &width, &height, &numColorChannels, 0);
    if (!textureData)
    {
        cout << "TEXTURE: failed to load texture" << endl;
        exit(EXIT_FAILURE);
    }
}

void Texture::bindTexture()
{
    glBindTexture(GL_TEXTURE_2D, textureID);
}

void Texture::setParameters()
{
    for (vector<array<GLuint, 3>>::iterator i = textureSettings.begin(); i != textureSettings.end(); i++)
    {
        glTexParameteri((*i)[0], (*i)[1], (*i)[2]);
    }
}
