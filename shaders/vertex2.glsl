#version 130

in vec3 aPos;
in vec3 aColor;

out vec3 color;

uniform float hOffset;

void main()
{
    gl_Position = vec4(aPos, 1.0);
    color = aColor;
}