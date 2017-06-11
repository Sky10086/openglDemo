//#version 330 core
attribute vec3 position;
attribute vec3 color;
attribute vec2 texCoord;

varying vec3 ourColor;
varying vec2 TexCoord;

uniform mat4 transform;

void main()
{
    gl_Position = transform*vec4(position, 1.0);
    ourColor = color;
    TexCoord = texCoord;
}