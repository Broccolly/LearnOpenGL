#define GLM_ENABLE_EXPERIMENTAL
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include "Texture.h"
#include "Mesh.h"

Vertex vertices[] = {
	{{-0.5f, -0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
	{{ 0.5f, -0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
	{{ 0.5f,  0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}},
	{{ 0.5f,  0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}},
	{{-0.5f,  0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},
	{{-0.5f, -0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
	{{-0.5f, -0.5f,  0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
	{{ 0.5f, -0.5f,  0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
	{{ 0.5f,  0.5f,  0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}},
	{{ 0.5f,  0.5f,  0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}},
	{{-0.5f,  0.5f,  0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},
	{{-0.5f, -0.5f,  0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
	{{-0.5f,  0.5f,  0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
	{{-0.5f,  0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}},
	{{-0.5f, -0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},
	{{-0.5f, -0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},
	{{-0.5f, -0.5f,  0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
	{{-0.5f,  0.5f,  0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
	{{ 0.5f,  0.5f,  0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
	{{ 0.5f,  0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}},
	{{ 0.5f, -0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},
	{{ 0.5f, -0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},
	{{ 0.5f, -0.5f,  0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
	{{ 0.5f,  0.5f,  0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
	{{-0.5f, -0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},
	{{ 0.5f, -0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}},
	{{ 0.5f, -0.5f,  0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
	{{ 0.5f, -0.5f,  0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
	{{-0.5f, -0.5f,  0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
	{{-0.5f, -0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},
	{{-0.5f,  0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},
	{{ 0.5f,  0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}},
	{{ 0.5f,  0.5f,  0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
	{{ 0.5f,  0.5f,  0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
	{{-0.5f,  0.5f,  0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
	{{-0.5f,  0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}} };

glm::vec3 positions[] = {
	glm::vec3(0.0f,  0.0f,  0.0f),
	glm::vec3(2.0f,  5.0f, -15.0f),
	glm::vec3(-1.5f, -2.2f, -2.5f),
	glm::vec3(-3.8f, -2.0f, -12.3f),
	glm::vec3(2.4f, -0.4f, -3.5f),
	glm::vec3(-1.7f,  3.0f, -7.5f),
	glm::vec3(1.3f, -2.0f, -2.5f),
	glm::vec3(1.5f,  2.0f, -2.5f),
	glm::vec3(1.5f,  0.2f, -1.5f),
	glm::vec3(-1.3f,  1.0f, -1.5f)
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0,0,width,height);
}

static const unsigned int WINDOW_WIDTH = 800;
static const unsigned int WINDOW_HEIGHT = 600;

float fov{ 45.0f };
double currentTime = 0.0f;
double deltaTime = 0.0f;
float cameraSpeed = 10.0f;
float mouseX = WINDOW_WIDTH / 2;
float mouseY = WINDOW_HEIGHT / 2;
float cameraSensitivity = 0.002f;
glm::vec3 cameraPos{ 0.0f, 0.0f, 3.0f };
glm::quat cameraOrientation{ 1.0f, 0.0f, 0.0f, 0.0f };


void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	fov -= (float)yoffset;
	if (fov < 1.0f)
		fov = 1.0f;
	if (fov > 80.0f)
		fov = 80.0f;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	float deltaX = xpos - mouseX;
	float deltaY = ypos - mouseY;

	mouseX = xpos;
	mouseY = ypos;

	glm::vec3 axis = cameraOrientation * glm::vec3(0.0f, 1.0f, 0.0f);

	cameraOrientation = glm::rotate(glm::quat_identity<float, glm::packed_highp>(), -cameraSensitivity * 1.0f * deltaX, glm::vec3(0.0f, 1.0f, 0.0f)) * cameraOrientation;

	glm::quat newQuat = glm::rotate(cameraOrientation, -cameraSensitivity * 1.0f * deltaY, glm::vec3(1.0f, 0.0f, 0.0f));

	// Shortcut to test newY against Y and stop overrotation vertically
	if (newQuat.w * newQuat.w + newQuat.y * newQuat.y - newQuat.x * newQuat.x - newQuat.z * newQuat.z >= 0)
	{
		cameraOrientation = newQuat;
	}
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		fov += 1.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		fov -= 1.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		cameraPos += cameraOrientation * glm::vec3(0.0f, 0.0f, -cameraSpeed * deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		cameraPos += cameraOrientation * glm::vec3(0.0f, 0.0f,  cameraSpeed * deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		cameraPos += cameraOrientation * glm::vec3(-cameraSpeed * deltaTime, 0.0f, 0.0f);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		cameraPos += cameraOrientation * glm::vec3(cameraSpeed * deltaTime, 0.0f,  0.0f);
	}
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		cameraPos += cameraOrientation * glm::vec3(0.0f, cameraSpeed * deltaTime, 0.0f);
	}
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		cameraPos += cameraOrientation * glm::vec3(0.0f, -cameraSpeed * deltaTime, 0.0f);
	}
}


int main(int argc, const char** argv)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW Window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialise GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glEnable(GL_DEPTH_TEST);

	// Textures
	unsigned int texture0, texture1;

	Texture tex0("Textures/wall.jpg", false);
	Texture tex1("Textures/awesomeface.png", true);


	//glBindTexture(GL_TEXTURE_2D, 0);

	Shader shader("shader.vs", "shader.fs");

	glm::mat4 trans = glm::mat4(1.0f); // Identity
	glm::mat4 view = glm::mat4(1.0f); // Identity

	Mesh mesh(vertices, sizeof(vertices) / sizeof(Vertex));
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		glfwSwapBuffers(window);
		glm::mat4 proj = glm::perspective(glm::radians(fov), (float)WINDOW_WIDTH/(float)WINDOW_HEIGHT, 0.1f, 100.0f); // Identity
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shader.Use();
		deltaTime = glfwGetTime() - currentTime;
		currentTime = glfwGetTime();
		shader.SetUniformFloat("time", currentTime);
		
		//cameraTransform = glm::rotate(glm::mat4(1.0f), 0.2f * deltaTime, glm::vec3(0.0f, 1.0f, 0.0f)) * cameraTransform;
		glm::mat4 cameraTransform = glm::identity<glm::mat4>();
		cameraTransform = glm::translate(cameraTransform, cameraPos);
		cameraTransform = cameraTransform * glm::toMat4(cameraOrientation);
		view = glm::inverse(cameraTransform);
		shader.SetUniformMat4("view", view);
		shader.SetUniformInt("ourTexture0", 0);
		shader.SetUniformInt("ourTexture1", 1);
		tex0.SetToTextureUnit(0);
		tex1.SetToTextureUnit(1);

		mesh.BindMesh();

		for (unsigned int i = 0; i < sizeof(positions) / sizeof(positions[0]); i++)
		{
			trans = glm::mat4(1.0f);
			trans = glm::translate(trans, positions[i]);
			trans = glm::rotate(trans, glm::radians(20.0f * i), glm::vec3(1.0, 0.3, 0.5));
			trans = glm::scale(trans, glm::vec3(1.0f));

			shader.SetUniformMat4("mat", trans);
			shader.SetUniformMat4("proj", proj);

			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		//glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(unsigned int), GL_UNSIGNED_INT, 0);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}