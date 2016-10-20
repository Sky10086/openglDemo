#include "shaders.h"
#include "texture.h"
#include "transformations.h"
enum Names
{
	toShaders = 0,
	toTexture,
	toTransform,
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
	default:
		break;
	}
}

int main()
{
	stratProcess(toTransform);
	return 0;
}