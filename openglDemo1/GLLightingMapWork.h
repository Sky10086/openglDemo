
#ifndef	GLLIGHTINGMAPWORK_H
#define GLLIGHTINGMAPWORK_H

#include "GLWork.h"

class GLLightingMapWork :public GLWork
{
public:
	GLLightingMapWork(const GLchar* vertexPath, const GLchar* fragmentPath, glm::vec3 cameraPos);
	~GLLightingMapWork();
	virtual void onDraw(int workIndex);

private:

};

GLLightingMapWork::GLLightingMapWork(const GLchar* vertexPath, const GLchar* fragmentPath, glm::vec3 cameraPos) :GLWork(vertexPath, fragmentPath, cameraPos)
{
}

GLLightingMapWork::~GLLightingMapWork()
{
}

void GLLightingMapWork::onDraw(int workIndex)
{
	if (workIndex == firstDraw)
	{
		Shader objectProgram = Shader("glsl//vertex_LightingMap_object.vs", "glsl//fragment_LightingMap_object.fra");

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

		/*ֻ��Ҫ����һ�ε���ѭ����������*/
		objectProgram.Use();
		glUniform1i(objectProgram.getUnifomLocation("material.diffuse"), 0);
		//��������Ĳ�������
		glUniform3f(objectProgram.getUnifomLocation("material.specular"), 0.5f, 0.5f, 0.5f);
		glUniform1f(objectProgram.getUnifomLocation("material.shininess"), 32.0f);
		// �ڴ�֮ǰ��Ҫ��������'ʹ��'��Ӧ����ɫ������(���趨uniform)
		GLint lightColorLoc = objectProgram.getUnifomLocation("lightColor");
		glUniform3f(lightColorLoc, 1.0f, 1.0f, 1.0f); // ���ɰѹ�Դ����Ϊ��ɫ

		//���ù�Դ����
		glUniform3f(objectProgram.getUnifomLocation("light.ambient"), 0.2f, 0.2f, 0.2f);
		glUniform3f(objectProgram.getUnifomLocation("light.diffuse"), 0.5f, 0.5f, 0.5f);// �����ǰ���������һ�㣬�����ῴ��������Ȼ
		glUniform3f(objectProgram.getUnifomLocation("light.specular"), 1.0f, 1.0f, 1.0f);;


		GLfloat lastFrame = 0.0f;
		GLfloat deltaTime = 0.0f;
		glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
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
			//�����Դλ��
			glUniform3f(objectProgram.getUnifomLocation("light.position"), lightPos.x, lightPos.y, lightPos.z);
			//���������λ�ã����۲���λ��
			glUniform3f(objectProgram.getUnifomLocation("viewPos"), mCamera.Position.x, mCamera.Position.y, mCamera.Position.z);

			glm::mat4 model2;
			glm::mat4 view = mCamera.GetViewMatrix();
			glm::mat4 projection;
			projection = glm::perspective(glm::radians(mCamera.Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
			//model = glm::translate(model, lightPos);
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model2));
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));


			// Bind diffuse map
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, diffuseMap);


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
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteVertexArrays(1, &lightVAO);
		// Terminate GLFW, clearing any resources allocated by GLFW.
		glfwTerminate();
		return;

	}
	else if (workIndex == secondDraw)//���Ͼ�����ͼ
	{
		Shader objectProgram = Shader("glsl//vertex_LightingMap_object2.vs", "glsl//fragment_LightingMap_object2.fra");

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

		//������ͼ
		GLuint specularMap;
		glGenTextures(1, &specularMap);
		image = SOIL_load_image("texImg\\lighting_maps_specular_color.png", &width, &height, 0, SOIL_LOAD_RGB);
		glBindTexture(GL_TEXTURE_2D, specularMap);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);
		SOIL_free_image_data(image);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
		glBindTexture(GL_TEXTURE_2D, 0);

		/*ֻ��Ҫ����һ�ε���ѭ����������*/
		objectProgram.Use();
		glUniform1i(objectProgram.getUnifomLocation("material.diffuse"), 0);
		//��������Ĳ�������
		glUniform1i(objectProgram.getUnifomLocation("material.specular"), 1);
		glUniform1f(objectProgram.getUnifomLocation("material.shininess"), 32.0f);
		// �ڴ�֮ǰ��Ҫ��������'ʹ��'��Ӧ����ɫ������(���趨uniform)
		GLint lightColorLoc = objectProgram.getUnifomLocation("lightColor");
		glUniform3f(lightColorLoc, 1.0f, 1.0f, 1.0f); // ���ɰѹ�Դ����Ϊ��ɫ

		//���ù�Դ����
		glUniform3f(objectProgram.getUnifomLocation("light.ambient"), 0.2f, 0.2f, 0.2f);
		glUniform3f(objectProgram.getUnifomLocation("light.diffuse"), 0.5f, 0.5f, 0.5f);// �����ǰ���������һ�㣬�����ῴ��������Ȼ
		glUniform3f(objectProgram.getUnifomLocation("light.specular"), 1.0f, 1.0f, 1.0f);;


		GLfloat lastFrame = 0.0f;
		GLfloat deltaTime = 0.0f;
		glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
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
			//�����Դλ��
			glUniform3f(objectProgram.getUnifomLocation("light.position"), lightPos.x, lightPos.y, lightPos.z);
			//���������λ�ã����۲���λ��
			glUniform3f(objectProgram.getUnifomLocation("viewPos"), mCamera.Position.x, mCamera.Position.y, mCamera.Position.z);

			glm::mat4 model2;
			glm::mat4 view = mCamera.GetViewMatrix();
			glm::mat4 projection;
			projection = glm::perspective(glm::radians(mCamera.Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
			//model = glm::translate(model, lightPos);
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model2));
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));


			// Bind diffuse map
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, diffuseMap);

			// bind specular 
			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, specularMap);


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
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteVertexArrays(1, &lightVAO);
		// Terminate GLFW, clearing any resources allocated by GLFW.
		glfwTerminate();
		return;
	}
	else if (workIndex == thirdDraw)
	{
		Shader objectProgram = Shader("glsl//vertex_LightingMap_object3.vs", "glsl//fragment_LightingMap_object3.fra");

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

		//������ͼ
		GLuint specularMap;
		glGenTextures(1, &specularMap);
		image = SOIL_load_image("texImg\\lighting_maps_specular.png", &width, &height, 0, SOIL_LOAD_RGB);
		glBindTexture(GL_TEXTURE_2D, specularMap);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);
		SOIL_free_image_data(image);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
		glBindTexture(GL_TEXTURE_2D, 0);

		//������ͼ
		GLuint emissionMap;
		glGenTextures(1, &emissionMap);
		image = SOIL_load_image("texImg\\matrix.jpg", &width, &height, 0, SOIL_LOAD_RGB);
		glBindTexture(GL_TEXTURE_2D, emissionMap);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);
		SOIL_free_image_data(image);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
		glBindTexture(GL_TEXTURE_2D, 0);

		/*ֻ��Ҫ����һ�ε���ѭ����������*/
		objectProgram.Use();
		glUniform1i(objectProgram.getUnifomLocation("material.diffuse"), 0);
		//��������Ĳ�������
		glUniform1i(objectProgram.getUnifomLocation("material.specular"), 1);
		glUniform1f(objectProgram.getUnifomLocation("material.shininess"), 64.0f);

		//���÷�����ͼ
		glUniform1i(objectProgram.getUnifomLocation("material.emission"), 2);
		// �ڴ�֮ǰ��Ҫ��������'ʹ��'��Ӧ����ɫ������(���趨uniform)
		GLint lightColorLoc = objectProgram.getUnifomLocation("lightColor");
		glUniform3f(lightColorLoc, 1.0f, 1.0f, 1.0f); // ���ɰѹ�Դ����Ϊ��ɫ

		//���ù�Դ����
		glUniform3f(objectProgram.getUnifomLocation("light.ambient"), 0.2f, 0.2f, 0.2f);
		glUniform3f(objectProgram.getUnifomLocation("light.diffuse"), 0.5f, 0.5f, 0.5f);// �����ǰ���������һ�㣬�����ῴ��������Ȼ
		glUniform3f(objectProgram.getUnifomLocation("light.specular"), 1.0f, 1.0f, 1.0f);;


		GLfloat lastFrame = 0.0f;
		GLfloat deltaTime = 0.0f;
		glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
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
			//�����Դλ��
			glUniform3f(objectProgram.getUnifomLocation("light.position"), lightPos.x, lightPos.y, lightPos.z);
			//���������λ�ã����۲���λ��
			glUniform3f(objectProgram.getUnifomLocation("viewPos"), mCamera.Position.x, mCamera.Position.y, mCamera.Position.z);

			glm::mat4 model2;
			glm::mat4 view = mCamera.GetViewMatrix();
			glm::mat4 projection;
			projection = glm::perspective(glm::radians(mCamera.Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
			//model = glm::translate(model, lightPos);
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model2));
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));


			// Bind diffuse map
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, diffuseMap);

			// bind specular 
			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, specularMap);

			//�󶨷�������
			glActiveTexture(GL_TEXTURE2);
			glBindTexture(GL_TEXTURE_2D, emissionMap);


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
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteVertexArrays(1, &lightVAO);
		// Terminate GLFW, clearing any resources allocated by GLFW.
		glfwTerminate();
		return;
	}
}

#endif