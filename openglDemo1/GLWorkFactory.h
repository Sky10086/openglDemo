#include "GLWork.h"
#include "GLTestWork.h"
#include "GLShaderWork.h"
#include "GLTestWork.h"
#include "GLTextureWork.h"
#include "GLBaceLightWork.h"
#include "GLMaterialsWork.h"
#include "GLLightingMapWork.h"

enum Names
{
	testWork = 0,
	shader,
	texture,
	baceLight,
	materials,
	lightingMap,
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
	case baceLight:
		vertex = "glsl//vertex_Color_light.vs";
		fragment = "glsl//fragment_Color_light.fra";
		return new GLBaceLightWork(vertex, fragment, cameraPos);
		break;
	case materials:
		vertex = "glsl//vertex_Color_light.vs";
		fragment = "glsl//fragment_Color_light.fra";
		return new GLMaterialsWork(vertex, fragment, cameraPos);
		break;
	case lightingMap:
		vertex = "glsl//vertex_Color_light.vs";
		fragment = "glsl//fragment_Color_light.fra";
		return new GLLightingMapWork(vertex, fragment, cameraPos);
		break;
	default:
		return NULL;
		break;
	}
	
}