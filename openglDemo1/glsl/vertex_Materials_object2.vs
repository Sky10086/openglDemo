#version 330 core
attribute vec3 position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

//法向量
attribute vec3 normal;
varying vec3 Normal;

//转换到世界空间中的坐标
varying vec3 FragPos;

void main()
{
    gl_Position = projection*view*model*vec4(position, 1.0);
	Normal = mat3(transpose(inverse(model))) * normal;
	FragPos = vec3(model*vec4(position,1.0));
}