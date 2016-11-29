#include "shaders.h"
#include "texture.h"
#include "transformations.h"
#include "CoordinateSystems.h"
enum Names
{
	toShaders = 0,
	toTexture,
	toTransform,
	toCoordinateSystems,
	toCoordinateSystems3D,
	toCoordinateSystems3DPro,
};

void stratProcess(int type)
{
	switch (type)
	{
	case toShaders:
		shaders();
		break;
	case toTexture:
		texture();
		break;
	case toTransform:
		transform();
		break;
	case toCoordinateSystems:
		CoordinateSystems();
		break;
	case toCoordinateSystems3D:
		CoordinateSystems2();
		break;
	case toCoordinateSystems3DPro:
		CoordinateSystems3();
		break;
	default:
		break;
	}
}

int main()
{
	stratProcess(toCoordinateSystems3DPro);
	return 0;
}