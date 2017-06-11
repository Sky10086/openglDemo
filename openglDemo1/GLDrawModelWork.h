#ifndef GLDRAWMODELWORK_H
#define GLDRAWMODELWORK_H
/**********************************************************
// Method: 
// Description: 对应模型加载一节，画出3D模型
// Author: 王炳琦 
// Date: 2016/12/11 21:38
// Returns: 
// Parameter: 
// History:
// G:\VisualStudio2013Projects\openglDemo1\openglDemo1\GLDrawModelWork.h
**********************************************************/
#include "GLWork.h"
#include "Model.h"

class GLDrawModelWork :public GLWork
{
public:
	GLDrawModelWork(const GLchar* vertexPath, const GLchar* fragmentPath, glm::vec3 cameraPos);
	~GLDrawModelWork();
	virtual void onDraw(int workIndex);

private:

};

GLDrawModelWork::GLDrawModelWork(const GLchar* vertexPath, const GLchar* fragmentPath, glm::vec3 cameraPos) :GLWork(vertexPath, fragmentPath, cameraPos)
{
}

GLDrawModelWork::~GLDrawModelWork()
{
}

void GLDrawModelWork::onDraw(int workIndex)
{
	if (workIndex == firstDraw)
	{

		Shader objectProgram = Shader("glsl//vertex_Model_object.vs", "glsl//fragment_Model_object.fra");
		Model humanModel("models//nanosuit//nanosuit.obj",false);
		//Model houseModel("models//OldHouse2//Old House Files//Old House 2 3D Models.obj",true);

		// Draw in wireframe
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		// Game loop
		GLfloat lastFrame = 0.0f;
		GLfloat deltaTime = 0.0f;
		while (!glfwWindowShouldClose(getWindow()))
		{
			// Set frame time
			GLfloat currentFrame = glfwGetTime();
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;

			// Check and call events
			glfwPollEvents();
			Do_Movement(deltaTime);

			// Clear the colorbuffer
			glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			objectProgram.Use();   // <-- Don't forget this one!
			// Transformation matrices
			glm::mat4 view = mCamera.GetViewMatrix();
			glm::mat4 projection;
			projection = glm::perspective(glm::radians(mCamera.Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));

			// Draw the loaded model
			//glm::mat4 model;
			//model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // Translate it down a bit so it's at the center of the scene
			//model = glm::scale(model, glm::vec3(0.05f, 0.05f, 0.05f));	// It's a bit too big for our scene, so scale it down
			//glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
			//houseModel.Draw(objectProgram);

			// Draw the loaded model
			glm::mat4 model2;
			model2 = glm::translate(model2, glm::vec3(0.0f, -1.0f, 0.0f)); // Translate it down a bit so it's at the center of the scene
			model2 = glm::scale(model2, glm::vec3(0.1f, 0.1f, 0.1f));	// It's a bit too big for our scene, so scale it down
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model2));
			humanModel.Draw(objectProgram);

			// Swap the buffers
			glfwSwapBuffers(getWindow());
		}

		glfwTerminate();
		return;
	}

	else if (workIndex == secondDraw)
	{
		Shader objectProgram = Shader("glsl//vertex_Model_object2.vs", "glsl//fragment_Model_object2.fra");
		//可用
		//Model humanModel("models//nanosuit//nanosuit.obj", false);
		//可用 绝对路径纹理要放在这个目录下C:\tdg\3D Models\House\Old House Texture
		//Model houseModel("models//OldHouse2//Old House Files//Old House 2 3D Models.obj",true);
		//可用 城堡
		//Model humanModel("models//Castle//Castle OBJ.obj", false); 
		//可用 多房子
		//Model humanModel("models//House Complex//House Complex.obj", false);

		Model humanModel("models//Deadpool//dead 123456.obj", true);

		// Draw in wireframe
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		GLfloat vertices[] = {
			// Positions           // Normals           // Texture Coords
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
			0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,

			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
			0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,

			-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

			0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

			-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f,
			0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,

			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f
		};

		GLuint VBO;
		glGenBuffers(1, &VBO);


		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	
		GLuint lightVAO;
		glGenVertexArrays(1, &lightVAO);

		glBindVertexArray(lightVAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glVertexAttribPointer(getProgram().getAttributeLocation("position"), 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(getProgram().getAttributeLocation("position"));
		glBindVertexArray(0);

		// Game loop
		GLfloat lastFrame = 0.0f;
		GLfloat deltaTime = 0.0f;
		// Point light positions
		glm::vec3 pointLightPositions[] = {
			glm::vec3(2.3f, -1.6f, -3.0f),
			glm::vec3(-1.7f, 0.9f, 1.0f)
		};

		while (!glfwWindowShouldClose(getWindow()))
		{
			// Set frame time
			GLfloat currentFrame = glfwGetTime();
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;

			// Check and call events
			glfwPollEvents();
			Do_Movement(deltaTime);

			// Clear the colorbuffer
			glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			objectProgram.Use();   // <-- Don't forget this one!
			// Transformation matrices
			glm::mat4 view = mCamera.GetViewMatrix();
			glm::mat4 projection;
			projection = glm::perspective(glm::radians(mCamera.Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));

			//输入观察者位置
			glUniform3f(objectProgram.getUnifomLocation("viewPos"), mCamera.Position.x, mCamera.Position.y, mCamera.Position.z);


			/*设置多个点光源的属性*/
			for (int i = 0; i < 2; i++)
			{
				std::ostringstream uniformName;
				uniformName << "pointLights[";
				uniformName << i;
				uniformName << "]";
				std::string first = uniformName.str();
				uniformName << ".position";
				//auto tempPos = lightPos * pointLightPositions[i];
				glm::vec3 lightPos = pointLightPositions[i];
				glUniform3f(objectProgram.getUnifomLocation(uniformName.str().c_str()), lightPos.x, lightPos.y, lightPos.z);
				uniformName.str("");
				uniformName << first;

				uniformName << ".ambient";
				glUniform3f(objectProgram.getUnifomLocation(uniformName.str().c_str()), 0.05f, 0.05f, 0.05f);
				uniformName.str("");
				uniformName << first;

				uniformName << ".diffuse";
				glUniform3f(objectProgram.getUnifomLocation(uniformName.str().c_str()), 1.0f, 1.0f, 1.0f);
				uniformName.str("");
				uniformName << first;

				uniformName << ".specular";
				glUniform3f(objectProgram.getUnifomLocation(uniformName.str().c_str()), 1.0f, 1.0f, 1.0f);
				uniformName.str("");
				uniformName << first;

				uniformName << ".constant";
				glUniform1f(objectProgram.getUnifomLocation(uniformName.str().c_str()), 1.0f);
				uniformName.str("");
				uniformName << first;

				uniformName << ".linear";
				glUniform1f(objectProgram.getUnifomLocation(uniformName.str().c_str()), 0.09f);
				uniformName.str("");
				uniformName << first;

				uniformName << ".quadratic";
				glUniform1f(objectProgram.getUnifomLocation(uniformName.str().c_str()), 0.032f);
				uniformName.str("");
				uniformName << first;
			}
			// Draw the loaded model
			//glm::mat4 model;
			//model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // Translate it down a bit so it's at the center of the scene
			//model = glm::scale(model, glm::vec3(0.05f, 0.05f, 0.05f));	// It's a bit too big for our scene, so scale it down
			//glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
			//houseModel.Draw(objectProgram);

			// Draw the loaded model
			glm::mat4 model2;
			model2 = glm::translate(model2, glm::vec3(0.0f, -1.0f, 0.0f)); // Translate it down a bit so it's at the center of the scene
			model2 = glm::scale(model2, glm::vec3(0.01f, 0.01f, 0.01f));	// It's a bit too big for our scene, so scale it down
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model2));
			humanModel.Draw(objectProgram);

			// Draw the lamps
			getProgram().Use();
			glBindVertexArray(lightVAO);
			glUniformMatrix4fv(glGetUniformLocation(getProgram().getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
			glUniformMatrix4fv(glGetUniformLocation(getProgram().getProgramID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
			for (GLuint i = 0; i < 2; i++)
			{
				model2 = glm::mat4();
				model2 = glm::translate(model2, pointLightPositions[i]);
				model2 = glm::scale(model2, glm::vec3(0.1f, 0.1f, 0.1f)); // Downscale lamp object (a bit too large)
				glUniformMatrix4fv(glGetUniformLocation(getProgram().getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model2));
				glDrawArrays(GL_TRIANGLES, 0, 36);
			}
			glBindVertexArray(0);
			// Swap the buffers
			glfwSwapBuffers(getWindow());
		}
		glDeleteBuffers(1, &VBO);
		glDeleteVertexArrays(1, &lightVAO);
		glfwTerminate();
		return;
	}
}

#endif