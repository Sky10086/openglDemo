#ifndef GLBACELIGHTWORK_H
#define GLBACELIGHTWORK_H

#include "GLWork.h"

class GLBaceLightWork :public GLWork
{
public:
	GLBaceLightWork(const GLchar* vertexPath, const GLchar* fragmentPath, glm::vec3 cameraPos);
	~GLBaceLightWork();
	virtual void onDraw(int workIndex);
private:

};

GLBaceLightWork::GLBaceLightWork(const GLchar* vertexPath, const GLchar* fragmentPath, glm::vec3 cameraPos) :GLWork(vertexPath, fragmentPath, cameraPos)
{
}

GLBaceLightWork::~GLBaceLightWork()
{
}

void GLBaceLightWork::onDraw(int workIndex)
{
	if (workIndex == firstDraw)
		{
			Shader objectProgram = Shader("glsl//vertex_BaceLight_object.vs", "glsl//fragment_BaseLight_object.fra");
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
				GLint objectColorLoc = objectProgram.getUnifomLocation("objectColor");
				GLint lightColorLoc = objectProgram.getUnifomLocation("lightColor");
				glUniform3f(objectColorLoc, 1.0f, 0.5f, 0.31f);// 我们所熟悉的珊瑚红
				glUniform3f(lightColorLoc, 1.0f, 1.0f, 1.0f); // 依旧把光源设置为白色


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
	else if (secondDraw == workIndex)//Gouraud 光照会产生插值的光照效果
		{
			Shader objectProgram = Shader("glsl//vertex_BaceLight_object _Gouraud.vs", "glsl//fragment_BaseLight_object_Gouraud.fra");
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
				GLint objectColorLoc = objectProgram.getUnifomLocation("objectColor");
				GLint lightColorLoc = objectProgram.getUnifomLocation("lightColor");
				glUniform3f(objectColorLoc, 1.0f, 0.5f, 0.31f);// 我们所熟悉的珊瑚红
				glUniform3f(lightColorLoc, 1.0f, 1.0f, 1.0f); // 依旧把光源设置为白色


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