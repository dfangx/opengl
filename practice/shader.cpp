#include <iostream>
#include <fstream>
#include <sstream>

#include "shader.h"

using namespace std;
using namespace glm;

Shader::Shader(string * shaderSourceFiles, GLuint * shaderStages):SHADER_STAGE_COMPILE(1), SHADER_LINK(2)
{
    if (shaderStages != NULL)
    {
        this -> shaderStages = shaderStages;
    }

    this -> shaderSourceFiles = shaderSourceFiles;

    shaderID = glCreateProgram();
    shaderStageID = 
    {
        glCreateShader(GL_VERTEX_SHADER),
        glCreateShader(GL_FRAGMENT_SHADER),
    };

    createShader();
};

string Shader::readShaderSource(string fileName)
{
    cout << "FILE_STREAM: reading from " << fileName << endl;
    ifstream input;
    stringstream buffer;
    input.open(fileName);
    buffer << input.rdbuf();
    input.close();
    
    return buffer.str();
}

void Shader::use()
{
    glUseProgram(shaderID);
}

void Shader::createShader()
{
    string tmp;

    for (int i = 0; i < 2; i++)
    {
        cout << "SHADER_STAGE: creating shader stage" << endl;

        cout << "SHADER_STAGE: reading shader stage source code" << endl;
        tmp = readShaderSource(shaderSourceFiles[i]).c_str(); 
        const char * shaderSourceCode = tmp.c_str();
        glShaderSource(shaderStageID[i], 1, &shaderSourceCode, NULL);

        glCompileShader(shaderStageID[i]);
        shaderChecks(shaderStageID[i], SHADER_STAGE_COMPILE);

        cout << "SHADER_STAGE: attaching compiled shader stage to shader object" << endl;
        glAttachShader(shaderID, shaderStageID[i]);
    }

    glBindAttribLocation(shaderID, 0, "aPos");
    glBindAttribLocation(shaderID, 1, "aColor");
    glBindAttribLocation(shaderID, 2, "aTexCoord");
    link();
    deleteShaderStage();
}

void Shader::deleteShaderStage()
{
    cout << "SHADER: deleting shader stages" << endl;
    for (vector<GLuint>::iterator i = shaderStageID.begin(); i != shaderStageID.end(); i++)
    {
        glDeleteShader(*i);
    }
}

void Shader::link()
{
    cout << "SHADER: linking shader" << endl;
    glLinkProgram(shaderID);
    shaderChecks(shaderID, SHADER_LINK);
}

void Shader::shaderChecks(GLuint id, const GLuint step)
{
    int success;
    char infoLog[512];

    if (step == SHADER_STAGE_COMPILE)
    {
        cout << "SHADER_STAGE: checking for compilation errors" << endl;
        glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    }
    else
    {
        cout << "SHADER: checking for linking errors" << endl;
        glGetShaderiv(id, GL_LINK_STATUS, &success);
    }


    if (!success)
    {
        glGetShaderInfoLog(id, 512, NULL, infoLog);
        if (step == SHADER_STAGE_COMPILE)
        {
            cout << "SHADER_STAGE: compilation failed. " << infoLog << endl;
        }
        else
        {
            cout << "SHADER: linking failed. " << infoLog << endl;
        }
        exit(EXIT_FAILURE);
    }

    if (step == SHADER_STAGE_COMPILE)
    {
        cout << "SHADER_STAGE: compilation successful" << endl;
    }
    else
    {
        cout << "SHADER: linking successful" << endl;
    }
}

void Shader::setUniformFloat(string uniformName, GLfloat value)
{
    glUniform1f(glGetUniformLocation(shaderID, uniformName.c_str()), value);
}

void Shader::setUniformInt(string uniformName, GLuint value)
{
    glUniform1i(glGetUniformLocation(shaderID, uniformName.c_str()), value);
}

void Shader::setUniformMatrix(string uniformName, mat4 value)
{
    glUniformMatrix4fv(glGetUniformLocation(shaderID, uniformName.c_str()), 1, GL_FALSE, value_ptr(value));
}
