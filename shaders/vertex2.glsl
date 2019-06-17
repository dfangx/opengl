#version 130

in vec3 aPos;
in vec3 aColor;
in vec2 aTexCoord;

out vec3 color;
out vec2 texCoord;

uniform mat4 transform;

void main()
{
    gl_Position = transform * vec4(aPos, 1.0);
    color = aColor;
    texCoord = aTexCoord;
}
