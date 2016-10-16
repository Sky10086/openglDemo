#include "shaders.h"
#include "texture.h"
enum Names
{
	toShaders = 0,
	toTexture,
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
	default:
		break;
	}
}

int main()
{
	stratProcess(toTexture);
	return 0;
}