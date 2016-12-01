#ifndef COLOR_H
#define COLOR_H

/*****************************************************************************
* @function name :
* @funcIntroduce :
* @inparam :
* @outparam :
* @author : xiaosheng
* @date : 2016/12/1 11:14
* @last change :
*****************************************************************************/

#include "shader.h"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


// Camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

/*摄像机移动相关*/
// Function prototypes
void key_callback_camera_color(GLFWwindow* window, int key, int scancode, int action, int mode);
void scroll_callback_color(GLFWwindow* window, double xoffset, double yoffset);
void mouse_callback_color(GLFWwindow* window, double xpos, double ypos);
void Do_Movement();
bool keys[1024];
GLfloat lastX_color = 400, lastY_color = 300;
// Light attributes
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
bool firstMouse_color = true;

GLfloat deltaTime_color = 0.0f;
GLfloat lastFrame_color = 0.0f;

int color()
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

	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback_camera_color);
	glfwSetCursorPosCallback(window, mouse_callback_color);
	glfwSetScrollCallback(window, scroll_callback_color);

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

	Shader lightProgram = Shader("glsl//vertex_Color_light.vs", "glsl//fragment_Color_light.fra");
	Shader objectProgram = Shader("glsl//vertex_Color_object.vs", "glsl//fragment_Color_object.fra");

	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		-0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f, 0.5f, -0.5f,
		0.5f, 0.5f, -0.5f,
		-0.5f, 0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f, -0.5f, 0.5f,
		0.5f, -0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f, 0.5f,
		-0.5f, -0.5f, 0.5f,

		-0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, 0.5f,
		-0.5f, 0.5f, 0.5f,

		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,

		-0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, 0.5f,
		0.5f, -0.5f, 0.5f,
		-0.5f, -0.5f, 0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f, 0.5f, -0.5f,
		0.5f, 0.5f, -0.5f,
		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f, -0.5f
	};

	GLuint VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);



	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	int attrID = glGetAttribLocation(objectProgram.getProgramID(), "position");
	attrID = glGetAttribLocation(lightProgram.getProgramID(), "position");
	attrID = glGetUniformLocation(objectProgram.getProgramID(), "model");
	attrID = glGetUniformLocation(objectProgram.getProgramID(), "view");
	attrID = glGetUniformLocation(objectProgram.getProgramID(), "projection");
	attrID = glGetUniformLocation(lightProgram.getProgramID(), "model");
	attrID = glGetUniformLocation(lightProgram.getProgramID(), "view");
	attrID = glGetUniformLocation(lightProgram.getProgramID(), "projection");


	glBindVertexArray(VAO);
	glVertexAttribPointer(glGetAttribLocation(objectProgram.getProgramID(), "position"), 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(glGetAttribLocation(objectProgram.getProgramID(), "position"));

	glBindVertexArray(0);

	GLuint lightVAO;
	glGenVertexArrays(1, &lightVAO);

	glBindVertexArray(lightVAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(glGetAttribLocation(lightProgram.getProgramID(), "position"), 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(glGetAttribLocation(lightProgram.getProgramID(), "position"));

	glBindVertexArray(0);






	// Game loop
	while (!glfwWindowShouldClose(window))
	{

		// Set frame time
		GLfloat currentFrame = glfwGetTime();
		deltaTime_color = currentFrame - lastFrame_color;
		lastFrame_color = currentFrame;

		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
		Do_Movement();
		// Render
		// Clear the colorbuffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		objectProgram.Use();

		// 在此之前不要忘记首先'使用'对应的着色器程序(来设定uniform)
		GLint objectColorLoc = glGetUniformLocation(objectProgram.getProgramID(), "objectColor");
		GLint lightColorLoc = glGetUniformLocation(objectProgram.getProgramID(), "lightColor");
		glUniform3f(objectColorLoc, 1.0f, 0.5f, 0.31f);// 我们所熟悉的珊瑚红
		glUniform3f(lightColorLoc, 1.0f, 1.0f, 1.0f); // 依旧把光源设置为白色

		glm::mat4 model2;
		glm::mat4 view = camera.GetViewMatrix();
		glm::mat4 projection;
		projection = glm::perspective(glm::radians(camera.Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
		//model = glm::translate(model, lightPos);
		glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model2));
		glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);

		// Activate shader
		lightProgram.Use();
		glm::mat4 model;
		model = glm::mat4();
		model = glm::translate(model, lightPos);
		model = glm::scale(model, glm::vec3(0.2f));
		glUniformMatrix4fv(glGetUniformLocation(lightProgram.getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(glGetUniformLocation(lightProgram.getProgramID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(glGetUniformLocation(lightProgram.getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));


		glBindVertexArray(lightVAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);

		// Swap the screen buffers
		glfwSwapBuffers(window);
	}
	// Properly de-allocate all resources once they've outlived their purpose
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &lightVAO);
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();

	return 0;
}


// Moves/alters the camera positions based on user input
void Do_Movement()
{
	// Camera controls
	if (keys[GLFW_KEY_W])
		camera.ProcessKeyboard(FORWARD, deltaTime_color);
	if (keys[GLFW_KEY_S])
		camera.ProcessKeyboard(BACKWARD, deltaTime_color);
	if (keys[GLFW_KEY_A])
		camera.ProcessKeyboard(LEFT, deltaTime_color);
	if (keys[GLFW_KEY_D])
		camera.ProcessKeyboard(RIGHT, deltaTime_color);
}

// Is called whenever a key is pressed/released via GLFW
void key_callback_camera_color(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	//cout << key << endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			keys[key] = true;
		else if (action == GLFW_RELEASE)
			keys[key] = false;
	}
}

void mouse_callback_color(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse_color)
	{
		lastX_color = xpos;
		lastY_color = ypos;
		firstMouse_color = false;
	}

	GLfloat xoffset = xpos - lastX_color;
	GLfloat yoffset = lastY_color - ypos;  // Reversed since y-coordinates go from bottom to left

	lastX_color = xpos;
	lastY_color = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}


void scroll_callback_color(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}

#endif