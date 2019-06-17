#version 130 
out vec4 FragColor;

in vec3 color;
in vec2 texCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{ 
    //FragColor = texture(ourTexture, texCoord);
    FragColor = mix(texture(texture1, texCoord), texture(texture2, vec2(-texCoord.x, texCoord.y)), 0.2);
}
