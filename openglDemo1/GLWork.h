#ifndef GLWORK_H
#define GLWORK_H
#include "shader.h"
#include "CameraDefine.h"
// GLM Mathematics
#include "../openglLIB/glm/glm.hpp"
#include "../openglLIB/glm/gtc/matrix_transform.hpp"
#include "../openglLIB/glm/gtc/type_ptr.hpp"

enum drawIndex
{
	firstDraw = 0,
	secondDraw,
	thirdDraw,
	forthDraw
};

class GLWork
{
public:
	GLWork(const GLchar* vertexPath, const GLchar* fragmentPath, glm::vec3 cameraPos);
	~GLWork();
	Shader getProgram();
	GLFWwindow* getWindow();
	//virtual void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);//键盘回调
	//virtual void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);//鼠标滚轮回调
	//virtual void mouse_callback(GLFWwindow* window, double xpos, double ypos);//鼠标回调
	virtual void Do_Movement(float deltaTime);//移动处理
	virtual void initWork();//初始化工作环境，创建窗口进行设置等
	virtual void onDraw(int workIndex);//画帧,一个章节有时有好几次实践，使用index来确定画哪一个实践
private:
	Shader mProgram;
	GLFWwindow* mWindows;
};

static bool mKey_Map[1024];
static GLfloat lastX;
static GLfloat lastY;
static bool firstMouse;
static Camera mCamera;

GLWork::GLWork(const GLchar* vertexPath, const GLchar* fragmentPath,glm::vec3 cameraPos)
{
	mCamera = Camera(cameraPos);
	lastX = WIDTH / 2.0f;
	lastY = HEIGHT / 2.0f;
	firstMouse = true;
	initWork();
	mProgram = Shader(vertexPath, fragmentPath);
}

GLWork::~GLWork()
{
}

Shader GLWork::getProgram()
{
	return this->mProgram;
}



GLFWwindow* GLWork::getWindow()
{
	return mWindows;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			mKey_Map[key] = true;
		else if (action == GLFW_RELEASE)
			mKey_Map[key] = false;
	}
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	GLfloat xoffset = xpos - lastX;
	GLfloat yoffset = lastY - ypos;  // Reversed since y-coordinates go from bottom to left

	lastX = xpos;
	lastY = ypos;

	mCamera.ProcessMouseMovement(xoffset, yoffset);

}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	mCamera.ProcessMouseScroll(yoffset);
}

void GLWork::Do_Movement(float deltaTime)
{
	// Camera controls
	if (mKey_Map[GLFW_KEY_W])
		mCamera.ProcessKeyboard(FORWARD, deltaTime);
	if (mKey_Map[GLFW_KEY_S])
		mCamera.ProcessKeyboard(BACKWARD, deltaTime);
	if (mKey_Map[GLFW_KEY_A])
		mCamera.ProcessKeyboard(LEFT, deltaTime);
	if (mKey_Map[GLFW_KEY_D])
		mCamera.ProcessKeyboard(RIGHT, deltaTime);
}

void GLWork::initWork()
{
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	/*这里给成员变量windows赋值*/
	mWindows = window;

	
	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window,scroll_callback);

	// GLFW Options
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();

	// Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);

	// Setup OpenGL options
	glEnable(GL_DEPTH_TEST);
}

void GLWork::onDraw(int workIndex)
{
	std::cout << "默认的" << std::endl;
}
#endif

