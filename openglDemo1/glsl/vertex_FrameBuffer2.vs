#version 330 core
attribute vec2 position;
attribute vec2 texCoords;

varying vec2 TexCoords;

void main()
{
    gl_Position = vec4(position.x,position.y,0.0, 1.0);
    TexCoords = texCoords;
}