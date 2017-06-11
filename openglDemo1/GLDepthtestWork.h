#ifndef GLDEPTHTESTWORK_H
#define GLDEPTHTESTWORK_H

/*****************************************************************************
* @function name : 
* @funcIntroduce :¶ÔÓ¦depth testingÕÂ½Ú
* @inparam : 
* @outparam : 
* @author : xiaosheng
* @date : 2016/12/14 17:21
* @last change : 
*****************************************************************************/

#include "GLWork.h"

class GLDepthTestWork :public GLWork
{
public:
	GLDepthTestWork(const GLchar* vertexPath, const GLchar* fragmentPath, glm::vec3 cameraPos);
	~GLDepthTestWork();
	virtual void onDraw(int workIndex);

private:

};

GLDepthTestWork::GLDepthTestWork(const GLchar* vertexPath, const GLchar* fragmentPath, glm::vec3 cameraPos) :GLWork(vertexPath, fragmentPath, cameraPos)
{
}

GLDepthTestWork::~GLDepthTestWork()
{
}

void GLDepthTestWork::onDraw(int workIndex)
{
	if (workIndex == firstDraw)
	{
		// Setup some OpenGL options
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS); // Set to always pass the depth test (same effect as glDisable(GL_DEPTH_TEST))

		// Set the object data (buffers, vertex attributes)
		GLfloat cubeVertices[] = {
			// Positions          // Texture Coords
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

			-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f
		};

		//set the floor
		GLfloat planeVertices[] = {
			// Positions            // Texture Coords (note we set these higher than 1 that together with GL_REPEAT as texture wrapping mode will cause the floor texture to repeat)
			5.0f, -0.5f, 5.0f, 3.0f, 0.0f,
			-5.0f, -0.5f, 5.0f, 0.0f, 0.0f,
			-5.0f, -0.5f, -5.0f, 0.0f, 3.0f,

			5.0f, -0.5f, 5.0f, 2.0f, 0.0f,
			-5.0f, -0.5f, -5.0f, 0.0f, 2.0f,
			5.0f, -0.5f, -5.0f, 2.0f, 2.0f
		};

		GLuint cubeVAO, cubeVBO;
		glGenVertexArrays(1, &cubeVAO);
		glGenBuffers(1, &cubeVBO);

		glBindVertexArray(cubeVAO);

		glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
		
		glEnableVertexAttribArray(getProgram().getAttributeLocation("position"));
		glVertexAttribPointer(getProgram().getAttributeLocation("position"), 3, GL_FLOAT, GL_FALSE, 5* sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(getProgram().getAttributeLocation("texCoords"));
		glVertexAttribPointer(getProgram().getAttributeLocation("texCoords"), 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3*sizeof(GLfloat)));
		glBindVertexArray(0);

		GLuint planeVAO, planeVBO;
		glGenVertexArrays(1, &planeVAO);
		glGenBuffers(1, &planeVBO);

		glBindVertexArray(planeVAO);

		glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), planeVertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(getProgram().getAttributeLocation("position"));
		glVertexAttribPointer(getProgram().getAttributeLocation("position"), 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(getProgram().getAttributeLocation("texCoords"));
		glVertexAttribPointer(getProgram().getAttributeLocation("texCoords"), 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
		glBindVertexArray(0);

		GLuint floor = loadTexture("texImg\\wall.jpg");
		GLuint box = loadTexture("texImg\\container2.png");

		GLfloat lastFrame = 0.0f;
		GLfloat deltaTime = 0.0f;
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

			getProgram().Use();

			glm::mat4 model;
			glm::mat4 view = mCamera.GetViewMatrix();
			glm::mat4 projection = glm::perspective(glm::radians(mCamera.Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
			glUniformMatrix4fv(glGetUniformLocation(getProgram().getProgramID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(glGetUniformLocation(getProgram().getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
			// Cubes

			glBindVertexArray(cubeVAO);
			glBindTexture(GL_TEXTURE_2D, box);  // We omit the glActiveTexture part since TEXTURE0 is already the default active texture unit. (sampler used in fragment is set to 0 as well as default)		
			model = glm::translate(model, glm::vec3(-1.0f, 0.0f, -1.0f));
			glUniformMatrix4fv(glGetUniformLocation(getProgram().getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 36);
			model = glm::mat4();
			model = glm::translate(model, glm::vec3(2.0f, 0.0f, 0.0f));
			glUniformMatrix4fv(glGetUniformLocation(getProgram().getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 36);

			glBindVertexArray(planeVAO);
			glBindTexture(GL_TEXTURE_2D, floor);
			model = glm::mat4();
			glUniformMatrix4fv(glGetUniformLocation(getProgram().getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 6);
			glBindVertexArray(0);

			// Swap the buffers
			glfwSwapBuffers(getWindow());

		}

		// Properly de-allocate all resources once they've outlived their purpose
		glDeleteVertexArrays(1, &cubeVAO);
		glDeleteBuffers(1, &cubeVBO);
		glDeleteVertexArrays(1, &planeVAO);
		glDeleteBuffers(1, &planeVBO);
		// Terminate GLFW, clearing any resources allocated by GLFW.
		glfwTerminate();
		return;
	}
	else if (workIndex == secondDraw)
	{
		// Setup some OpenGL options
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS); // Set to always pass the depth test (same effect as glDisable(GL_DEPTH_TEST))

		Shader objectProgram = Shader("glsl//vertex_DepthTest2.vs", "glsl//fragment_DepthTest2.fra");
		// Set the object data (buffers, vertex attributes)
		GLfloat cubeVertices[] = {
			// Positions          // Texture Coords
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

			-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f
		};

		//set the floor
		GLfloat planeVertices[] = {
			// Positions            // Texture Coords (note we set these higher than 1 that together with GL_REPEAT as texture wrapping mode will cause the floor texture to repeat)
			5.0f, -0.5f, 5.0f, 3.0f, 0.0f,
			-5.0f, -0.5f, 5.0f, 0.0f, 0.0f,
			-5.0f, -0.5f, -5.0f, 0.0f, 3.0f,

			5.0f, -0.5f, 5.0f, 2.0f, 0.0f,
			-5.0f, -0.5f, -5.0f, 0.0f, 2.0f,
			5.0f, -0.5f, -5.0f, 2.0f, 2.0f
		};

		GLuint cubeVAO, cubeVBO;
		glGenVertexArrays(1, &cubeVAO);
		glGenBuffers(1, &cubeVBO);

		glBindVertexArray(cubeVAO);

		glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(objectProgram.getAttributeLocation("position"));
		glVertexAttribPointer(objectProgram.getAttributeLocation("position"), 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(objectProgram.getAttributeLocation("texCoords"));
		glVertexAttribPointer(objectProgram.getAttributeLocation("texCoords"), 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
		glBindVertexArray(0);

		GLuint planeVAO, planeVBO;
		glGenVertexArrays(1, &planeVAO);
		glGenBuffers(1, &planeVBO);

		glBindVertexArray(planeVAO);

		glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), planeVertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(objectProgram.getAttributeLocation("position"));
		glVertexAttribPointer(objectProgram.getAttributeLocation("position"), 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(objectProgram.getAttributeLocation("texCoords"));
		glVertexAttribPointer(objectProgram.getAttributeLocation("texCoords"), 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
		glBindVertexArray(0);

		GLuint floor = loadTexture("texImg\\wall.jpg");
		GLuint box = loadTexture("texImg\\container2.png");

		GLfloat lastFrame = 0.0f;
		GLfloat deltaTime = 0.0f;
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

			glm::mat4 model;
			glm::mat4 view = mCamera.GetViewMatrix();
			glm::mat4 projection = glm::perspective(glm::radians(mCamera.Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
			// Cubes

			glBindVertexArray(cubeVAO);
			glBindTexture(GL_TEXTURE_2D, box);  // We omit the glActiveTexture part since TEXTURE0 is already the default active texture unit. (sampler used in fragment is set to 0 as well as default)		
			model = glm::translate(model, glm::vec3(-1.0f, 0.0f, -1.0f));
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 36);
			model = glm::mat4();
			model = glm::translate(model, glm::vec3(2.0f, 0.0f, 0.0f));
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 36);

			glBindVertexArray(planeVAO);
			glBindTexture(GL_TEXTURE_2D, floor);
			model = glm::mat4();
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 6);
			glBindVertexArray(0);

			glBindTexture(GL_TEXTURE_2D, 0);

			// Swap the buffers
			glfwSwapBuffers(getWindow());

		}

		// Properly de-allocate all resources once they've outlived their purpose
		glDeleteVertexArrays(1, &cubeVAO);
		glDeleteBuffers(1, &cubeVBO);
		glDeleteVertexArrays(1, &planeVAO);
		glDeleteBuffers(1, &planeVBO);
		// Terminate GLFW, clearing any resources allocated by GLFW.
		glfwTerminate();
		return;
	}
	else if (workIndex == thirdDraw)
	{
		// Setup some OpenGL options
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS); // Set to always pass the depth test (same effect as glDisable(GL_DEPTH_TEST))

		Shader objectProgram = Shader("glsl//vertex_DepthTest3.vs", "glsl//fragment_DepthTest3.fra");
		// Set the object data (buffers, vertex attributes)
		GLfloat cubeVertices[] = {
			// Positions          // Texture Coords
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

			-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f
		};

		//set the floor
		GLfloat planeVertices[] = {
			// Positions            // Texture Coords (note we set these higher than 1 that together with GL_REPEAT as texture wrapping mode will cause the floor texture to repeat)
			5.0f, -0.5f, 5.0f, 3.0f, 0.0f,
			-5.0f, -0.5f, 5.0f, 0.0f, 0.0f,
			-5.0f, -0.5f, -5.0f, 0.0f, 3.0f,

			5.0f, -0.5f, 5.0f, 2.0f, 0.0f,
			-5.0f, -0.5f, -5.0f, 0.0f, 2.0f,
			5.0f, -0.5f, -5.0f, 2.0f, 2.0f
		};

		GLuint cubeVAO, cubeVBO;
		glGenVertexArrays(1, &cubeVAO);
		glGenBuffers(1, &cubeVBO);

		glBindVertexArray(cubeVAO);

		glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(objectProgram.getAttributeLocation("position"));
		glVertexAttribPointer(objectProgram.getAttributeLocation("position"), 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(objectProgram.getAttributeLocation("texCoords"));
		glVertexAttribPointer(objectProgram.getAttributeLocation("texCoords"), 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
		glBindVertexArray(0);

		GLuint planeVAO, planeVBO;
		glGenVertexArrays(1, &planeVAO);
		glGenBuffers(1, &planeVBO);

		glBindVertexArray(planeVAO);

		glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), planeVertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(objectProgram.getAttributeLocation("position"));
		glVertexAttribPointer(objectProgram.getAttributeLocation("position"), 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(objectProgram.getAttributeLocation("texCoords"));
		glVertexAttribPointer(objectProgram.getAttributeLocation("texCoords"), 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
		glBindVertexArray(0);

		GLuint floor = loadTexture("texImg\\wall.jpg");
		GLuint box = loadTexture("texImg\\container2.png");

		GLfloat lastFrame = 0.0f;
		GLfloat deltaTime = 0.0f;
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

			glm::mat4 model;
			glm::mat4 view = mCamera.GetViewMatrix();
			glm::mat4 projection = glm::perspective(glm::radians(mCamera.Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
			// Cubes

			glBindVertexArray(cubeVAO);
			glBindTexture(GL_TEXTURE_2D, box);  // We omit the glActiveTexture part since TEXTURE0 is already the default active texture unit. (sampler used in fragment is set to 0 as well as default)		
			model = glm::translate(model, glm::vec3(-1.0f, 0.0f, -1.0f));
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 36);
			model = glm::mat4();
			model = glm::translate(model, glm::vec3(2.0f, 0.0f, 0.0f));
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 36);

			glBindVertexArray(planeVAO);
			glBindTexture(GL_TEXTURE_2D, floor);
			model = glm::mat4();
			glUniformMatrix4fv(glGetUniformLocation(objectProgram.getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 6);
			glBindVertexArray(0);

			glBindTexture(GL_TEXTURE_2D, 0);

			// Swap the buffers
			glfwSwapBuffers(getWindow());

		}

		// Properly de-allocate all resources once they've outlived their purpose
		glDeleteVertexArrays(1, &cubeVAO);
		glDeleteBuffers(1, &cubeVBO);
		glDeleteVertexArrays(1, &planeVAO);
		glDeleteBuffers(1, &planeVBO);
		// Terminate GLFW, clearing any resources allocated by GLFW.
		glfwTerminate();
		return;
	}
}
#endif