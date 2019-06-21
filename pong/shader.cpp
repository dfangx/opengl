#include <iostream>
#include <fstream>
#include <sstream>

#include "shader.h"

Shader::Shader(std::vector<std::string> shaderSourceFiles)
{
    shaderID = glCreateProgram();
    shaderStageIdList = 
    {
        glCreateShader(GL_VERTEX_SHADER),
        glCreateShader(GL_FRAGMENT_SHADER),
    };

    compileShader(shaderSourceFiles);
    linkShader();
    deleteShaderStage();
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

void Shader::compileShader(std::vector<std::string> shaderSourceFiles)
{
    std::string tmp;

    for (GLuint i = 0; i < shaderStageIdList.size(); i++)
    {
        tmp = loadShaderSource(shaderSourceFiles[i]);
        const char * shaderSourceCode = tmp.c_str();

        glShaderSource(shaderStageIdList[i], 1, &shaderSourceCode, NULL);

        glCompileShader(shaderStageIdList[i]);

        if (!isCompiled(shaderStageIdList[i]))
        {
            std::cout << "ERROR: SHADER_COMPILE: compilation failed. application terminating" << std::endl;
            exit(EXIT_FAILURE);
        }

        glAttachShader(shaderID, shaderStageIdList[i]);
    }

    glBindAttribLocation(shaderID, 0, "aPos");
    glBindAttribLocation(shaderID, 1, "aColor");
}

void Shader::linkShader()
{
    glLinkProgram(shaderID);
    if(!isLinked())
    {
        std::cout << "ERROR: SHADER_LINK: linking failed. application terminating" << std::endl;
        exit(EXIT_FAILURE);
    }
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
        std::cout << "ERROR: SHADER_LINK: linking failed. " << infoLog << std::endl;
        return false;
    }

    return true;
}

void Shader::deleteShaderStage()
{
    for (GLuint i = 0; i < shaderStageIdList.size(); i++)
    {
        glDeleteShader(shaderStageIdList[i]);
    }
}
