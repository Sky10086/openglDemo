#version 330 core
attribute vec3 position;
attribute vec3 normal;

varying vec3 Normal;
varying vec3 Position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

//纹理坐标
varying vec2 TexCoords;
void main()
{
    gl_Position = projection*view*model*vec4(position, 1.0);
	Normal = mat3(transpose(inverse(model))) * normal;
    Position = vec3(model * vec4(position, 1.0f));
}