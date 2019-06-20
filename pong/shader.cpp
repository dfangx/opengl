#include <iostream>
#include <fstream>
#include <sstream>

#include "shader.h"

Shader::Shader()
{
    shaderID = glCreateProgram();
    shaderStageIdList = 
    {
        glCreateShader(GL_VERTEX_SHADER),
        glCreateShader(GL_FRAGMENT_SHADER),
    };

    createShader();
}

void Shader::createShader()
{
}

void Shader::use()
{
    glUseProgram(shaderID);
}

std::string Shader::loadShaderSource(std::string fileName)
{
    std::cout << "FILE_STREAM: reading from " << fileName << std::endl;
    std::ifstream input;
    std::stringstream buffer;

    input.open(fileName);
    buffer << input.rdbuf();
    input.close();
    
    return buffer.str();
}

void Shader::compileShader()
{
}

void Shader::linkShader()
{
    glLinkProgram(shaderID);
    isLinked();
}

bool Shader::isCompiled(GLuint id)
{
    GLint success;
    char infoLog[512];

    glGetShaderiv(id, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(id, 512, NULL, infoLog);
        std::cout << "ERROR: SHADER_COMPILE: compilation failed. " << infoLog << std::endl;
        return false;
    }

    return true;
}

bool Shader::isLinked()
{
    GLint success;
    char infoLog[512];

    glGetShaderiv(shaderID, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
        std::cout << "SHADER: linking failed. " << infoLog << std::endl;
        return false;
    }

    return true;
}

void Shader::deleteShaderStage()
{
    for (GLuint i = 0; i < (GLuint)ShaderNames::NUM_SHADERS; i++)
    {
        glDeleteShader(shaderStageIdList[i]);
    }
}
