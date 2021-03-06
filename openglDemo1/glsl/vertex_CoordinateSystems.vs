#version 330 core
attribute vec3 position;
attribute vec3 color;
attribute vec2 texCoord;

varying vec3 ourColor;
varying vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection*view*model*vec4(position, 1.0);
    ourColor = color;
    TexCoord = texCoord;
}