#include "GLWork.h"
#include "GLTestWork.h"
#include "GLShaderWork.h"
#include "GLTestWork.h"
#include "GLTextureWork.h"
#include "GLBaceLightWork.h"
#include "GLMaterialsWork.h"
#include "GLLightingMapWork.h"
#include "GLLightcastersWork.h"
#include "GLMultiLightWork.h"
#include "GLDrawModelWork.h"
#include "GLDepthtestWork.h"
#include "GLStencilTestWork.h"
#include "GLBlendWork.h"
#include "GLFaceCullWork.h"
#include "GLFramebufferWork.h"
#include "GLCubemapWork.h"

enum Names
{
	testWork = 0,
	shader,
	texture,
	baceLight,
	materials,
	lightingMap,
	lightCasters,
	multiLights,
	drawModel,
	depthTest,
	stencilTest,
	blend,
	faceCull,
	frameBuffer,
	cubeMap,
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
	case lightCasters:
		vertex = "glsl//vertex_Color_light.vs";
		fragment = "glsl//fragment_Color_light.fra";
		return new GLLightCastersWork(vertex, fragment, cameraPos);
		break;
	case multiLights:
		vertex = "glsl//vertex_Color_light.vs";
		fragment = "glsl//fragment_Color_light.fra";
		return new GLMultiLightsWork(vertex, fragment, cameraPos);
		break;
	case drawModel:
		vertex = "glsl//vertex_Color_light.vs";
		fragment = "glsl//fragment_Color_light.fra";
		return new GLDrawModelWork(vertex, fragment, cameraPos);
		break;
	case depthTest:
		vertex = "glsl//vertex_DepthTest.vs";
		fragment = "glsl//fragment_DepthTest.fra";
		return new GLDepthTestWork(vertex, fragment, cameraPos);
		break;
	case stencilTest:
		vertex = "glsl//vertex_DepthTest.vs";
		fragment = "glsl//fragment_DepthTest.fra";
		return new GLStencilTestWork(vertex, fragment, cameraPos);
		break;
	case  blend:
		vertex = "glsl//vertex_Blend.vs";
		fragment = "glsl//fragment_Blend.fra";
		return new GLBlendWork(vertex, fragment, cameraPos);
		break;
	case faceCull:
		vertex = "glsl//vertex_Blend.vs";
		fragment = "glsl//fragment_Blend.fra";
		return new GLFaceCullWork(vertex, fragment, cameraPos);
		break;
	case frameBuffer:
		vertex = "glsl//vertex_Blend.vs";
		fragment = "glsl//fragment_Blend.fra";
		return new GLFrameBufferWork(vertex, fragment, cameraPos);
		break;
	case cubeMap:
		vertex = "glsl//vertex_Blend.vs";
		fragment = "glsl//fragment_Blend.fra";
		return new GLCubemapWork(vertex, fragment, cameraPos);
		break;
	default:
		return NULL;
		break;
	}
	
}