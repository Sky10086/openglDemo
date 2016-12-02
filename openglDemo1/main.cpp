//#include "shaders.h"
//#include "texture.h"
//#include "transformations.h"
//#include "CoordinateSystems.h"
//#include "Camera.h"
//#include "Color.h"
//#include "testAnswer.h"
//enum Names
//{
//	toShaders = 0,
//	toTexture,
//	toTransform,
//	toCoordinateSystems,
//	toCoordinateSystems3D,
//	toCoordinateSystems3DPro,
//	toCamera,
//	toCameraPro,
//	toColor,
//};
//
//void stratProcess(int type)
//{
//	switch (type)
//	{
//	case toShaders:
//		shaders();
//		break;
//	case toTexture:
//		texture();
//		break;
//	case toTransform:
//		transform();
//		break;
//	case toCoordinateSystems:
//		CoordinateSystems();
//		break;
//	case toCoordinateSystems3D:
//		CoordinateSystems2();
//		break;
//	case toCoordinateSystems3DPro:
//		CoordinateSystems3();
//		break;
//	case toCamera:
//		testcamera();
//		break;
//	case toCameraPro:
//		cameraPro();
//		break;
//	case toColor:
//		color();
//		break;
//	default:
//		break;
//	}
//}

#include "GLTestWork.h"

int main()
{
	//stratProcess(toColor);
	//testAnswer();
	GLTestWork *testWork = new GLTestWork("glsl//vertex_Color_light.vs", "glsl//fragment_Color_light.fra", glm::vec3(0.0f, 0.0f, 3.0f));
	testWork->initWork();
	testWork->onDraw();
	return 0;
}

/*****************************************************************************
* @function name : 
* @funcIntroduce :���demo��������Ѿ��������ý�������ѧϰ�ˣ����ܸ�дͬ���ĺ�����ȫ�ֱ�������ɣ��ض������Ƶ��
������Ҫ�Դ˿���ع���
* @inparam : 
* @outparam : 
* @author : xiaosheng
* @date : 2016/12/1 21:11
* @last change : 
*****************************************************************************/