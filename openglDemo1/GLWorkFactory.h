#include "GLWork.h"
#include "GLTestWork.h"
#include "GLShaderWork.h"
#include "GLTestWork.h"
#include "GLTextureWork.h"

enum Names
{
	testWork = 0,
	shader,
	texture,
};


GLWork *workCreater(int name)
{
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	GLchar *vertex = "";
	GLchar *fragment = "";
	switch (name)
	{
	case testWork:
		vertex = "glsl//vertex_Color_light.vs";
		fragment = "glsl//fragment_Color_light.fra";
		return new GLTestWork(vertex, fragment, cameraPos);
		break;
	case shader:
		vertex = "glsl//vertex1.vs";
		fragment = "glsl//fragment1.fra";
		return new GLShaderWork(vertex, fragment, cameraPos);
		break;
	case texture:
		vertex = "glsl//vertex_texture.vs";
		fragment = "glsl//fragment_texture.fra";
		return new GLTextureWork(vertex, fragment, cameraPos);
		break;
	default:
		break;
	}
	
}