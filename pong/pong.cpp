#include <iostream>
#include "pong.h"

void Pong::init()
{
}

void Pong::processInput()
{
}

void Pong::update()
{
}

void Pong::render()
{
    rM.getShader(DataStorage::ShaderNames::BOXSHADER)->use();
    rM.getVAO(DataStorage::VAONames::VAO_1)->bindVAO();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

