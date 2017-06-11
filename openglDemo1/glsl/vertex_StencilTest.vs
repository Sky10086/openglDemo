#version 330 core
attribute vec3 position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

//纹理坐标
varying vec2 TexCoords;
void main()
{
    gl_Position = projection*view*model*vec4(position, 1.0);
}