#ifndef GLTEXTUREWORK_H
#define GLTEXTUREWORK_H
/**********************************************************
// Method:
// Description: 纹理，对应于learnOpengl 纹理一节
// Author: 王炳琦
// Date: 2016/10/16 21:37
// Returns:
// Parameter:
// History:
// G:\VisualStudio2013Projects\openglDemo1\openglDemo1\texture.h
**********************************************************/
#include "GLWork.h"

float filterFactor = 0.2f;

class GLTextureWork :public GLWork
{
public:
	GLTextureWork(const GLchar* vertexPath, const GLchar* fragmentPath, glm::vec3 cameraPos);
	~GLTextureWork();
	virtual void onDraw(int workIndex);
private:

};

GLTextureWork::GLTextureWork(const GLchar* vertexPath, const GLchar* fragmentPath, glm::vec3 cameraPos) :GLWork(vertexPath, fragmentPath, cameraPos)
{
}

GLTextureWork::~GLTextureWork()
{
}

void GLTextureWork::onDraw(int workIndex)
{
	GLuint textureImg, textureImg2;
	glGenTextures(1, &textureImg);
	glBindTexture(GL_TEXTURE_2D, textureImg);

	// Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	int imgWidth, imgHeight;
	UCHAR *img = SOIL_load_image("texImg\\container.jpg", &imgWidth, &imgHeight, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
	glGenerateMipmap(GL_TEXTURE_2D);

	SOIL_free_image_data(img);
	glBindTexture(GL_TEXTURE_2D, 0);//为何要及时解绑

	// Texture 2
	// ===================
	glGenTextures(1, &textureImg2);
	glBindTexture(GL_TEXTURE_2D, textureImg2);
	// Set our texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	// Load, create texture and generate mipmaps
	img = SOIL_load_image("texImg\\awesomeface.png", &imgWidth, &imgHeight, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imgWidth, imgWidth, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(img);
	glBindTexture(GL_TEXTURE_2D, 0);



	GLfloat vertices[] = {
		//     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
		-0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,   // 左上
		0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,   // 右上
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,   // 左下
		0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f    // 右下
	};

	//顶点索引数组
	GLuint index[] = {
		0, 1, 2, // First Triangle
		0, 2, 3  // Second Triangle
	};

	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	/*
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);*/

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	//纹理坐标 texCoord
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

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



		// Activate shader
		getProgram().Use();

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textureImg);
		glUniform1i(glGetUniformLocation(getProgram().getProgramID(), "ourTexture1"), 0);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, textureImg2);
		glUniform1i(glGetUniformLocation(getProgram().getProgramID(), "ourTexture2"), 1);

		glUniform1f(glGetUniformLocation(getProgram().getProgramID(), "filterRatio"), filterFactor);

		// Draw container
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		// Swap the screen buffers
		glfwSwapBuffers(getWindow());
	}
	// Properly de-allocate all resources once they've outlived their purpose
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	//glDeleteBuffers(1, &EBO);
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();

	return ;
}




#endif // !TEXTURE_H
