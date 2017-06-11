/**********************************************************
// Method: 
// Description: 多光源，将平行光、定向光、和聚光灯效果合在一个场景中
// Author: 王炳琦 
// Date: 2016/12/11 0:50
// Returns: 
// Parameter: 
// History:
// G:\VisualStudio2013Projects\openglDemo1\openglDemo1\GLMultiLight.h
**********************************************************/

#ifndef GLMULTILIGHTSWORK_H
#define GLMULTILIGHTSWORK_H

#include "GLWork.h"
class GLMultiLightsWork :public GLWork
{
public:
	GLMultiLightsWork(const GLchar* vertexPath, const GLchar* fragmentPath, glm::vec3 cameraPos);
	~GLMultiLightsWork();
	virtual void onDraw(int workIndex);

private:

};

GLMultiLightsWork::GLMultiLightsWork(const GLchar* vertexPath, const GLchar* fragmentPath, glm::vec3 cameraPos) :GLWork(vertexPath, fragmentPath, cameraPos)
{
}

GLMultiLightsWork::~GLMultiLightsWork()
{
}

void GLMultiLightsWork::onDraw(int workIndex)
{
	if (workIndex == firstDraw)
	{

		Shader objectProgram = Shader("glsl//vertex_MultiLights_object.vs", "glsl//fragment_MultiLights_object.fra");

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

		GLuint VAO, VBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(objectProgram.getAttributeLocation("position"), 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(objectProgram.getAttributeLocation("position"));
		glVertexAttribPointer(objectProgram.getAttributeLocation("normal"), 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(objectProgram.getAttributeLocation("normal"));
		glVertexAttribPointer(objectProgram.getAttributeLocation("texCoords"), 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
		glEnableVertexAttribArray(objectProgram.getAttributeLocation("texCoords"));

		glBindVertexArray(0);

		GLuint lightVAO;
		glGenVertexArrays(1, &lightVAO);

		glBindVertexArray(lightVAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glVertexAttribPointer(getProgram().getAttributeLocation("position"), 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(getProgram().getAttributeLocation("position"));
		glBindVertexArray(0);

		GLuint diffuseMap;
		glGenTextures(1, &diffuseMap);
		int width, height;
		unsigned char* image;
		image = SOIL_load_image("texImg\\container2.png", &width, &height, 0, SOIL_LOAD_RGB);
		glBindTexture(GL_TEXTURE_2D, diffuseMap);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);
		SOIL_free_image_data(image);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
		glBindTexture(GL_TEXTURE_2D, 0);

		//镜面贴图
		GLuint specularMap;
		glGenTextures(1, &specularMap);
		image = SOIL_load_image("texImg\\container2_specular.png", &width, &height, 0, SOIL_LOAD_RGB);
		glBindTexture(GL_TEXTURE_2D, specularMap);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);
		SOIL_free_image_data(image);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
		glBindTexture(GL_TEXTURE_2D, 0);

		/*只需要设置一次的在循环外面设置*/
		objectProgram.Use();
		glUniform1i(objectProgram.getUnifomLocation("material.diffuse"), 0);
		//设置物体的材质属性
		glUniform1i(objectProgram.getUnifomLocation("material.specular"), 1);
		glUniform1f(objectProgram.getUnifomLocation("material.shininess"), 32.0f);
		// 在此之前不要忘记首先'使用'对应的着色器程序(来设定uniform)

		//设置平行光源属性
		glUniform3f(objectProgram.getUnifomLocation("dirLight.ambient"), 1.0f, 0.05f, 0.05f);
		glUniform3f(objectProgram.getUnifomLocation("dirLight.diffuse"), 0.4f, 0.4f, 0.4f);// 让我们把这个光调暗一点，这样会看起来更自然
		glUniform3f(objectProgram.getUnifomLocation("dirLight.specular"), 0.5f, 0.5f, 0.5f);


		GLfloat lastFrame = 0.0f;
		GLfloat deltaTime = 0.0f;
		glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

		/*创建多个3D箱子，使用此数组做偏移*/
		glm::vec3 cubePositions[] = {
			glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3(2.0f, 5.0f, -15.0f),
			glm::vec3(-1.5f, -2.2f, -2.5f),
			glm::vec3(-3.8f, -2.0f, -12.3f),
			glm::vec3(2.4f, -0.4f, -3.5f),
			glm::vec3(-1.7f, 3.0f, -7.5f),
			glm::vec3(1.3f, -2.0f, -2.5f),
			glm::vec3(1.5f, 2.0f, -2.5f),
			glm::vec3(1.5f, 0.2f, -1.5f),
			glm::vec3(-1.3f, 1.0f, -1.5f)
		};

		glm::vec3 pointLightPositions[] = {
			glm::vec3(0.7f, 0.2f, 2.0f),
			glm::vec3(2.3f, -3.3f, -4.0f),
			glm::vec3(-4.0f, 2.0f, -12.0f),
			glm::vec3(0.0f, 0.0f, -3.0f)
		};
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


			lightPos.x = 1.0f + sin((glfwGetTime())) * 2.0f;
			lightPos.y = sin((glfwGetTime()) / 2.0f) * 1.0f;
			//传入光源位置
			//glUniform3f(objectProgram.getUnifomLocation("light.position"), lightPos.x, lightPos.y, lightPos.z);
			//glUniform3f(objectProgram.getUnifomLocation("light.position"), 1.2f, 1.0f, 2.0f);
			/*设置多个点光源的属性*/
			for (int i = 0; i < 4; i++)
			{
				std::ostringstream uniformName;
				uniformName << "pointLights[";
				uniformName << i;
				uniformName << "]";
				std::string first = uniformName.str();
				uniformName << ".position";
				auto tempPos = lightPos * pointLightPositions[i];
				//lightPos = pointLightPositions[i];
				glUniform3f(objectProgram.getUnifomLocation(uniformName.str().c_str()), tempPos.x, tempPos.y, tempPos.z);
				uniformName.str("");
				uniformName << first;

				uniformName << ".ambient";
				glUniform3f(objectProgram.getUnifomLocation(uniformName.str().c_str()), 0.05f, 0.05f, 0.05f);
				uniformName.str("");
				uniformName << first;

				uniformName << ".diffuse";
				glUniform3f(objectProgram.getUnifomLocation(uniformName.str().c_str()), 0.0f, 0.8f, 0.0f);
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

			//改为平行定向光光照方向向下
			glUniform3f(objectProgram.getUnifomLocation("dirLight.direction"), -0.2f, -1.0f, -0.3f);
			//传入摄像机位置，即观察者位置
			glUniform3f(objectProgram.getUnifomLocation("viewPos"), mCamera.Position.x, mCamera.Position.y, mCamera.Position.z);

			//传入spotLight光的参数  unifrom太多，运行时会报错，
			glUniform3f(objectProgram.getUnifomLocation("spotLight.position"), mCamera.Position.x, mCamera.Position.y, mCamera.Position.z);
			glUniform3f(objectProgram.getUnifomLocation("spotLight.direction"), mCamera.Front.x, mCamera.Front.y, mCamera.Front.z);
			glUniform1f(objectProgram.getUnifomLocation("spotLight.cutOff"), glm::radians(12.5f));
			glUniform1f(objectProgram.getUnifomLocation("spotLight.outerCutOff"), glm::radians(17.5f));
			glUniform3f(objectProgram.getUnifomLocation("spotLight.ambient"), 0.0f, 0.0f, 0.0f);
			glUniform3f(objectProgram.getUnifomLocation("spotLight.diffuse"), 1.0f, 1.0f, 1.0f);// 
			glUniform3f(objectProgram.getUnifomLocation("spotLight.specular"), 1.0f, 1.0f, 1.0f);
			glUniform1f(objectProgram.getUnifomLocation("spotLight.constant"), 1.0f);
			glUniform1f(objectProgram.getUnifomLocation("spotLight.linear"), 0.09f);
			glUniform1f(objectProgram.getUnifomLocation("spotLight.quadratic"), 0.032f);




			glm::mat4 view = mCamera.GetViewMatrix();
			glm::mat4 projection;
			projection = glm::perspective(glm::radians(mCamera.Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));


			// Bind diffuse map
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, diffuseMap);

			// bind specular 
			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, specularMap);


			glm::mat4 model2;
			glBindVertexArray(VAO);
			for (int i = 0; i < 10; i++)
			{
				model2 = glm::mat4();
				model2 = glm::translate(model2, cubePositions[i]);
				GLfloat angle = glfwGetTime()*20.0f * i;
				//GLfloat angle = 20.0f * i;

				model2 = glm::rotate(model2, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
				glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model2));
				glDrawArrays(GL_TRIANGLES, 0, 36);
			}
			glBindVertexArray(0);

			// Activate shader
			getProgram().Use();
			glUniformMatrix4fv(glGetUniformLocation(getProgram().getProgramID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(glGetUniformLocation(getProgram().getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));

			glBindVertexArray(lightVAO);
			for (int i = 0; i < 4;i++)
			{
				glm::mat4 model;
				model = glm::mat4();
				model = glm::translate(model, pointLightPositions[i]);
				//model = glm::translate(model, lightPos * pointLightPositions[i]);
				
				model = glm::scale(model, glm::vec3(0.2f));
				glUniformMatrix4fv(glGetUniformLocation(getProgram().getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 0, 36);
			}
			glBindVertexArray(0);

			// Swap the screen buffers
			glfwSwapBuffers(getWindow());
		}

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