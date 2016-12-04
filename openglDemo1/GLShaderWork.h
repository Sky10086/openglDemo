#ifndef GLSHADERWORK_H
#define GLSHADERWORK_H
/********************************************************** 
// Description: 着色器，对应于learnOpenGL着色器这节
// Author: 王炳琦 Date: 2016/10/16 21:12
**********************************************************/
#include "GLWork.h"

class GLShaderWork :public GLWork
{
public:
	GLShaderWork(const GLchar* vertexPath, const GLchar* fragmentPath, glm::vec3 cameraPos) :GLWork(vertexPath, fragmentPath, cameraPos)
	{
	}

	~GLShaderWork()
	{
	}
	virtual void onDraw(int workIndex);
private:

};

void GLShaderWork::onDraw(int workIndex)
{

	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		// Positions         // Colors
		0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // Bottom Right
		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // Bottom Left
		0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f   // Top 
	};

	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0); // Unbind VAO

	// Game loop
	while (!glfwWindowShouldClose(getWindow()))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw the triangle
		getProgram().Use();
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		// Swap the screen buffers
		glfwSwapBuffers(getWindow());
	}
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();

	return;
}

#endif // !SHADERS_H
