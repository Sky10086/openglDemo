#ifndef GLFACECULLWORK_H
#define GLFACECULLWORK_H

#include "GLWork.h"

class GLFaceCullWork :public GLWork
{
public:
	GLFaceCullWork(const GLchar* vertexPath, const GLchar* fragmentPath, glm::vec3 cameraPos);
	~GLFaceCullWork();
	virtual void onDraw(int workIndex);
private:

};

GLFaceCullWork::GLFaceCullWork(const GLchar* vertexPath, const GLchar* fragmentPath, glm::vec3 cameraPos) :GLWork(vertexPath, fragmentPath, cameraPos)
{
}

GLFaceCullWork::~GLFaceCullWork()
{
}

void GLFaceCullWork::onDraw(int workIndex)
{
	if (workIndex == firstDraw)
	{
		/*
		Remember: to specify vertices in a counter-clockwise winding order you need to visualize the triangle
		as if you're in front of the triangle and from that point of view, is where you set their order.

		To define the order of a triangle on the right side of the cube for example, you'd imagine yourself looking
		straight at the right side of the cube, and then visualize the triangle and make sure their order is specified
		in a counter-clockwise order. This takes some practice, but try visualizing this yourself and see that this
		is correct.
		*/

		GLfloat cubeVertices[] = {
			// Back face
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, // Bottom-left
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f, // top-right
			0.5f, -0.5f, -0.5f, 1.0f, 0.0f, // bottom-right         
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f, // top-right
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, // bottom-left
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, // top-left
			// Front face
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, // bottom-left
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f, // bottom-right
			0.5f, 0.5f, 0.5f, 1.0f, 1.0f, // top-right
			0.5f, 0.5f, 0.5f, 1.0f, 1.0f, // top-right
			-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, // top-left
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, // bottom-left
			// Left face
			-0.5f, 0.5f, 0.5f, 1.0f, 0.0f, // top-right
			-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, // top-left
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, // bottom-left
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, // bottom-left
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, // bottom-right
			-0.5f, 0.5f, 0.5f, 1.0f, 0.0f, // top-right
			// Right face
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f, // top-left
			0.5f, -0.5f, -0.5f, 0.0f, 1.0f, // bottom-right
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f, // top-right         
			0.5f, -0.5f, -0.5f, 0.0f, 1.0f, // bottom-right
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f, // top-left
			0.5f, -0.5f, 0.5f, 0.0f, 0.0f, // bottom-left     
			// Bottom face
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, // top-right
			0.5f, -0.5f, -0.5f, 1.0f, 1.0f, // top-left
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f, // bottom-left
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f, // bottom-left
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, // bottom-right
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, // top-right
			// Top face
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, // top-left
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f, // bottom-right
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f, // top-right     
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f, // bottom-right
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, // top-left
			-0.5f, 0.5f, 0.5f, 0.0f, 0.0f  // bottom-left        
		};

		// Setup some OpenGL options
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS); // Set to always pass the depth test (same effect as glDisable(GL_DEPTH_TEST))

		//设置透明度混合相关选项
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBlendEquation(GL_FUNC_ADD);

		//设置面剔除选项
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);

		// Set the object data (buffers, vertex attributes)
		GLfloat cubeVertices_old[] = {
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

		GLfloat transparentVertices[] = {
			// Positions         // Texture Coords (swapped y coordinates because texture is flipped upside down)
			0.0f, 0.5f, 0.0f, 0.0f, 0.0f,
			0.0f, -0.5f, 0.0f, 0.0f, 1.0f,
			1.0f, -0.5f, 0.0f, 1.0f, 1.0f,

			0.0f, 0.5f, 0.0f, 0.0f, 0.0f,
			1.0f, -0.5f, 0.0f, 1.0f, 1.0f,
			1.0f, 0.5f, 0.0f, 1.0f, 0.0f
		};

		GLuint cubeVAO, cubeVBO;
		glGenVertexArrays(1, &cubeVAO);
		glGenBuffers(1, &cubeVBO);

		glBindVertexArray(cubeVAO);

		glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(getProgram().getAttributeLocation("position"));
		glVertexAttribPointer(getProgram().getAttributeLocation("position"), 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(getProgram().getAttributeLocation("texCoords"));
		glVertexAttribPointer(getProgram().getAttributeLocation("texCoords"), 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
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

		GLuint grassVAO, grassVBO;
		glGenVertexArrays(1, &grassVAO);
		glGenBuffers(1, &grassVBO);

		glBindVertexArray(grassVAO);
		glBindBuffer(GL_ARRAY_BUFFER, grassVBO);

		glBufferData(GL_ARRAY_BUFFER, sizeof(transparentVertices), transparentVertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(getProgram().getAttributeLocation("position"));
		glVertexAttribPointer(getProgram().getAttributeLocation("position"), 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(getProgram().getAttributeLocation("texCoords"));
		glVertexAttribPointer(getProgram().getAttributeLocation("texCoords"), 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
		glBindVertexArray(0);

		GLuint floor = loadTexture("texImg\\wall.jpg");
		GLuint box = loadTexture("texImg\\container2.png");
		GLuint grass = loadTextureForRGBA("texImg\\blending_transparent_window.png");

		std::vector<glm::vec3> vegetation;
		vegetation.push_back(glm::vec3(-1.5f, 0.0f, -0.48f));
		vegetation.push_back(glm::vec3(1.5f, 0.0f, 0.51f));
		vegetation.push_back(glm::vec3(0.0f, 0.0f, 0.7f));
		vegetation.push_back(glm::vec3(-0.3f, 0.0f, -2.3f));
		vegetation.push_back(glm::vec3(0.5f, 0.0f, -0.6f));

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


			std::map<float, glm::vec3> sorted;
			for (GLuint i = 0; i < vegetation.size(); i++) // windows contains all window positions
			{
				GLfloat distance = glm::length(mCamera.Position - vegetation[i]);
				sorted[distance] = vegetation[i];
			}

			glBindVertexArray(grassVAO);
			glBindTexture(GL_TEXTURE_2D, grass);
			for (std::map<float, glm::vec3>::reverse_iterator it = sorted.rbegin(); it != sorted.rend(); it++)
			{
				model = glm::mat4();
				model = translate(model, it->second);
				glUniformMatrix4fv(getProgram().getUnifomLocation("model"), 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 0, 6);
			}
			glBindVertexArray(0);
			// Swap the buffers
			glfwSwapBuffers(getWindow());

		}

		// Properly de-allocate all resources once they've outlived their purpose
		glDeleteVertexArrays(1, &cubeVAO);
		glDeleteBuffers(1, &cubeVBO);
		glDeleteVertexArrays(1, &planeVAO);
		glDeleteBuffers(1, &planeVBO);
		glDeleteVertexArrays(1, &grassVAO);
		glDeleteBuffers(1, &grassVBO);
		// Terminate GLFW, clearing any resources allocated by GLFW.
		glfwTerminate();
		return;
	}
}

#endif