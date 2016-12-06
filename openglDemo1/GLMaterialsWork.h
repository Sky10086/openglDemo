#ifndef GLMATERIALSWORK_H
#define GLMATERIALSWORK_H

#include "GLWork.h"

/*****************************************************************************
* @function name : 
* @funcIntroduce :对应Materials这一章
* @inparam : 
* @outparam : 
* @author : xiaosheng
* @date : 2016/12/6 23:36
* @last change : 
*****************************************************************************/
class GLMaterialsWork :public GLWork
{
public:
	GLMaterialsWork(const GLchar* vertexPath, const GLchar* fragmentPath, glm::vec3 cameraPos);
	~GLMaterialsWork();
	virtual void onDraw(int workIndex);

private:

};

GLMaterialsWork::GLMaterialsWork(const GLchar* vertexPath, const GLchar* fragmentPath, glm::vec3 cameraPos) :GLWork(vertexPath, fragmentPath, cameraPos)
{

}

GLMaterialsWork::~GLMaterialsWork()
{
}

void GLMaterialsWork::onDraw(int workIndex)
{
	if (workIndex == firstDraw)
	{
		Shader objectProgram = Shader("glsl//vertex_Materials_object1.vs", "glsl//fragment_Materials_object1.fra");
		// Set up vertex data (and buffer(s)) and attribute pointers
		GLfloat vertices[] = {
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
			0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
			0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
			0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,

			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
			0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
			0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
			0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,

			-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,

			0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,

			-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,

			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f
		};

		GLuint VAO, VBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


		glBindVertexArray(VAO);
		glVertexAttribPointer(objectProgram.getAttributeLocation("position"), 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(objectProgram.getAttributeLocation("position"));
		glVertexAttribPointer(objectProgram.getAttributeLocation("normal"), 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(objectProgram.getAttributeLocation("normal"));

		glBindVertexArray(0);

		GLuint lightVAO;
		glGenVertexArrays(1, &lightVAO);

		glBindVertexArray(lightVAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glVertexAttribPointer(getProgram().getAttributeLocation("position"), 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(getProgram().getAttributeLocation("position"));

		glBindVertexArray(0);

		GLfloat lastFrame = 0.0f;
		GLfloat deltaTime = 0.0f;
		glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
		// Game loop
		while (!glfwWindowShouldClose(getWindow()))
		{

			// Set frame time
			GLfloat currentFrame = glfwGetTime();
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;

			// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
			glfwPollEvents();
			Do_Movement(deltaTime);
			// Render
			// Clear the colorbuffer
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			objectProgram.Use();

			// 在此之前不要忘记首先'使用'对应的着色器程序(来设定uniform)
			//GLint objectColorLoc = objectProgram.getUnifomLocation("objectColor");
			GLint lightColorLoc = objectProgram.getUnifomLocation("lightColor");
			//glUniform3f(objectColorLoc, 1.0f, 0.5f, 0.31f);// 我们所熟悉的珊瑚红
			glUniform3f(lightColorLoc, 1.0f, 1.0f, 1.0f); // 依旧把光源设置为白色

			//设置物体的材质属性
			glUniform3f(objectProgram.getUnifomLocation("material.ambient"), 1.0f, 0.5f, 0.31f);
			glUniform3f(objectProgram.getUnifomLocation("material.diffuse"), 1.0f, 0.5f, 0.31f);
			glUniform3f(objectProgram.getUnifomLocation("material.specular"), 0.5f, 0.5f, 0.5f);
			glUniform1f(objectProgram.getUnifomLocation("material.shininess"), 32.0f);


			lightPos.x = 1.0f + sin((glfwGetTime())) * 2.0f;
			lightPos.y = sin((glfwGetTime()) / 2.0f) * 1.0f;
			//传入光源位置
			glUniform3f(objectProgram.getUnifomLocation("lightPos"), lightPos.x, lightPos.y, lightPos.z);
			//传入摄像机位置，即观察者位置
			glUniform3f(objectProgram.getUnifomLocation("viewPos"), mCamera.Position.x, mCamera.Position.y, mCamera.Position.z);

			GLuint uniformID = objectProgram.getUnifomLocation("lightPos");
			uniformID = objectProgram.getUnifomLocation("viewPos");

			glm::mat4 model2;
			glm::mat4 view = mCamera.GetViewMatrix();
			glm::mat4 projection;
			projection = glm::perspective(glm::radians(mCamera.Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
			//model = glm::translate(model, lightPos);
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model2));
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));

			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 36);
			glBindVertexArray(0);

			// Activate shader
			getProgram().Use();
			glm::mat4 model;
			model = glm::mat4();
			model = glm::translate(model, lightPos);
			model = glm::scale(model, glm::vec3(0.2f));
			glUniformMatrix4fv(glGetUniformLocation(getProgram().getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
			glUniformMatrix4fv(glGetUniformLocation(getProgram().getProgramID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(glGetUniformLocation(getProgram().getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));


			glBindVertexArray(lightVAO);
			glDrawArrays(GL_TRIANGLES, 0, 36);
			glBindVertexArray(0);

			// Swap the screen buffers
			glfwSwapBuffers(getWindow());
		}
		// Properly de-allocate all resources once they've outlived their purpose
		// Properly de-allocate all resources once they've outlived their purpose
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteVertexArrays(1, &lightVAO);
		// Terminate GLFW, clearing any resources allocated by GLFW.
		glfwTerminate();
		return;
	}
	else if (workIndex == secondDraw)
	{
		Shader objectProgram = Shader("glsl//vertex_Materials_object2.vs", "glsl//fragment_Materials_object2.fra");
		// Set up vertex data (and buffer(s)) and attribute pointers
		GLfloat vertices[] = {
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
			0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
			0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
			0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,

			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
			0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
			0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
			0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,

			-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,

			0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,

			-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,

			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f
		};

		GLuint VAO, VBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


		glBindVertexArray(VAO);
		glVertexAttribPointer(objectProgram.getAttributeLocation("position"), 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(objectProgram.getAttributeLocation("position"));
		glVertexAttribPointer(objectProgram.getAttributeLocation("normal"), 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(objectProgram.getAttributeLocation("normal"));

		glBindVertexArray(0);

		GLuint lightVAO;
		glGenVertexArrays(1, &lightVAO);

		glBindVertexArray(lightVAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glVertexAttribPointer(getProgram().getAttributeLocation("position"), 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(getProgram().getAttributeLocation("position"));

		glBindVertexArray(0);

		GLfloat lastFrame = 0.0f;
		GLfloat deltaTime = 0.0f;
		glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
		// Game loop
		while (!glfwWindowShouldClose(getWindow()))
		{

			// Set frame time
			GLfloat currentFrame = glfwGetTime();
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;

			// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
			glfwPollEvents();
			Do_Movement(deltaTime);
			// Render
			// Clear the colorbuffer
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			objectProgram.Use();

			// 在此之前不要忘记首先'使用'对应的着色器程序(来设定uniform)
			//GLint objectColorLoc = objectProgram.getUnifomLocation("objectColor");
			//GLint lightColorLoc = objectProgram.getUnifomLocation("lightColor");
			//glUniform3f(objectColorLoc, 1.0f, 0.5f, 0.31f);// 我们所熟悉的珊瑚红
			//glUniform3f(lightColorLoc, 1.0f, 1.0f, 1.0f); // 依旧把光源设置为白色

			//设置物体的材质属性
			glUniform3f(objectProgram.getUnifomLocation("material.ambient"), 1.0f, 0.5f, 0.31f);
			glUniform3f(objectProgram.getUnifomLocation("material.diffuse"), 1.0f, 0.5f, 0.31f);
			glUniform3f(objectProgram.getUnifomLocation("material.specular"), 0.5f, 0.5f, 0.5f);
			glUniform1f(objectProgram.getUnifomLocation("material.shininess"), 32.0f);

			// Set lights properties
			glm::vec3 lightColor;
			lightColor.x = sin(glfwGetTime() * 2.0f);
			lightColor.y = sin(glfwGetTime() * 0.7f);
			lightColor.z = sin(glfwGetTime() * 1.3f);
			glm::vec3 diffuseColor = lightColor * glm::vec3(0.5f); // Decrease the influence
			glm::vec3 ambientColor = diffuseColor * glm::vec3(0.2f); // Low influence


			//设置光源属性
			glUniform3f(objectProgram.getUnifomLocation("light.ambient"), ambientColor.x, ambientColor.y, ambientColor.z);
			glUniform3f(objectProgram.getUnifomLocation("light.diffuse"), diffuseColor.x, diffuseColor.y, diffuseColor.z);// 让我们把这个光调暗一点，这样会看起来更自然
			glUniform3f(objectProgram.getUnifomLocation("light.specular"), 1.0f, 1.0f, 1.0f);


			lightPos.x = 1.0f + sin((glfwGetTime())) * 2.0f;
			lightPos.y = sin((glfwGetTime()) / 2.0f) * 1.0f;
			//传入光源位置
			glUniform3f(objectProgram.getUnifomLocation("lightPos"), lightPos.x, lightPos.y, lightPos.z);
			//传入摄像机位置，即观察者位置
			glUniform3f(objectProgram.getUnifomLocation("viewPos"), mCamera.Position.x, mCamera.Position.y, mCamera.Position.z);

			GLuint uniformID = objectProgram.getUnifomLocation("lightPos");
			uniformID = objectProgram.getUnifomLocation("viewPos");

			glm::mat4 model2;
			glm::mat4 view = mCamera.GetViewMatrix();
			glm::mat4 projection;
			projection = glm::perspective(glm::radians(mCamera.Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
			//model = glm::translate(model, lightPos);
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model2));
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));

			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 36);
			glBindVertexArray(0);

			// Activate shader
			getProgram().Use();
			glm::mat4 model;
			model = glm::mat4();
			model = glm::translate(model, lightPos);
			model = glm::scale(model, glm::vec3(0.2f));
			glUniformMatrix4fv(glGetUniformLocation(getProgram().getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
			glUniformMatrix4fv(glGetUniformLocation(getProgram().getProgramID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(glGetUniformLocation(getProgram().getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));


			glBindVertexArray(lightVAO);
			glDrawArrays(GL_TRIANGLES, 0, 36);
			glBindVertexArray(0);

			// Swap the screen buffers
			glfwSwapBuffers(getWindow());
		}
		// Properly de-allocate all resources once they've outlived their purpose
		// Properly de-allocate all resources once they've outlived their purpose
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteVertexArrays(1, &lightVAO);
		// Terminate GLFW, clearing any resources allocated by GLFW.
		glfwTerminate();
		return;
	}

	else if (workIndex == thirdDraw)
	{

		Shader objectProgram = Shader("glsl//vertex_Materials_object3.vs", "glsl//fragment_Materials_object3.fra");
		// Set up vertex data (and buffer(s)) and attribute pointers
		GLfloat vertices[] = {
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
			0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
			0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
			0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,

			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
			0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
			0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
			0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,

			-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,

			0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,

			-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,

			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f
		};

		GLuint VAO, VBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


		glBindVertexArray(VAO);
		glVertexAttribPointer(objectProgram.getAttributeLocation("position"), 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(objectProgram.getAttributeLocation("position"));
		glVertexAttribPointer(objectProgram.getAttributeLocation("normal"), 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(objectProgram.getAttributeLocation("normal"));

		glBindVertexArray(0);

		GLuint lightVAO;
		glGenVertexArrays(1, &lightVAO);

		glBindVertexArray(lightVAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glVertexAttribPointer(getProgram().getAttributeLocation("position"), 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(getProgram().getAttributeLocation("position"));

		glBindVertexArray(0);

		GLfloat lastFrame = 0.0f;
		GLfloat deltaTime = 0.0f;
		glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
		// Game loop
		while (!glfwWindowShouldClose(getWindow()))
		{

			// Set frame time
			GLfloat currentFrame = glfwGetTime();
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;

			// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
			glfwPollEvents();
			Do_Movement(deltaTime);
			// Render
			// Clear the colorbuffer
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			objectProgram.Use();

			// 在此之前不要忘记首先'使用'对应的着色器程序(来设定uniform)
			//GLint objectColorLoc = objectProgram.getUnifomLocation("objectColor");
			//GLint lightColorLoc = objectProgram.getUnifomLocation("lightColor");
			//glUniform3f(objectColorLoc, 1.0f, 0.5f, 0.31f);// 我们所熟悉的珊瑚红
			//glUniform3f(lightColorLoc, 1.0f, 1.0f, 1.0f); // 依旧把光源设置为白色

			//设置物体的材质属性
			glUniform3f(objectProgram.getUnifomLocation("material.ambient"), 0.0f, 0.1f, 0.06f);
			glUniform3f(objectProgram.getUnifomLocation("material.diffuse"), 0.0f, 0.50980392f, 0.50980392f);
			glUniform3f(objectProgram.getUnifomLocation("material.specular"), 0.50196078f, 0.50196078f, 0.50196078f);
			glUniform1f(objectProgram.getUnifomLocation("material.shininess"), 0.25f*128.0);

			// Set lights properties
			glm::vec3 lightColor;
			lightColor.x = sin(glfwGetTime() * 2.0f);
			lightColor.y = sin(glfwGetTime() * 0.7f);
			lightColor.z = sin(glfwGetTime() * 1.3f);
			glm::vec3 diffuseColor = lightColor * glm::vec3(0.5f); // Decrease the influence
			glm::vec3 ambientColor = diffuseColor * glm::vec3(0.2f); // Low influence


			//设置光源属性
			glUniform3f(objectProgram.getUnifomLocation("light.ambient"), 1.0f, 1.0f, 1.0f);
			glUniform3f(objectProgram.getUnifomLocation("light.diffuse"), 1.0f, 1.0f, 1.0f);// 让我们把这个光调暗一点，这样会看起来更自然
			glUniform3f(objectProgram.getUnifomLocation("light.specular"), 1.0f, 1.0f, 1.0f);


			lightPos.x = 1.0f + sin((glfwGetTime())) * 2.0f;
			lightPos.y = sin((glfwGetTime()) / 2.0f) * 1.0f;
			//传入光源位置
			glUniform3f(objectProgram.getUnifomLocation("lightPos"), lightPos.x, lightPos.y, lightPos.z);
			//传入摄像机位置，即观察者位置
			glUniform3f(objectProgram.getUnifomLocation("viewPos"), mCamera.Position.x, mCamera.Position.y, mCamera.Position.z);

			GLuint uniformID = objectProgram.getUnifomLocation("lightPos");
			uniformID = objectProgram.getUnifomLocation("viewPos");

			glm::mat4 model2;
			glm::mat4 view = mCamera.GetViewMatrix();
			glm::mat4 projection;
			projection = glm::perspective(glm::radians(mCamera.Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
			//model = glm::translate(model, lightPos);
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model2));
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));

			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 36);
			glBindVertexArray(0);

			// Activate shader
			getProgram().Use();
			glm::mat4 model;
			model = glm::mat4();
			model = glm::translate(model, lightPos);
			model = glm::scale(model, glm::vec3(0.2f));
			glUniformMatrix4fv(glGetUniformLocation(getProgram().getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
			glUniformMatrix4fv(glGetUniformLocation(getProgram().getProgramID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(glGetUniformLocation(getProgram().getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));


			glBindVertexArray(lightVAO);
			glDrawArrays(GL_TRIANGLES, 0, 36);
			glBindVertexArray(0);

			// Swap the screen buffers
			glfwSwapBuffers(getWindow());
		}
		// Properly de-allocate all resources once they've outlived their purpose
		// Properly de-allocate all resources once they've outlived their purpose
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteVertexArrays(1, &lightVAO);
		// Terminate GLFW, clearing any resources allocated by GLFW.
		glfwTerminate();
		return;
	}
}
#endif