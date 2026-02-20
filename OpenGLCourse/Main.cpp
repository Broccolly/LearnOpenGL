#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"
#include "Texture.h"
#include "Mesh.h"
#include "Camera.h"

Vertex vertices[] = {
	//       POS                    NORMAL             COLOUR           UV
	{{-0.5f, -0.5f, -0.5f}, { 0.0f, 0.0f,-1.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
	{{ 0.5f, -0.5f, -0.5f}, { 0.0f, 0.0f,-1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
	{{ 0.5f,  0.5f, -0.5f}, { 0.0f, 0.0f,-1.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 1.0f}},
	{{ 0.5f,  0.5f, -0.5f}, { 0.0f, 0.0f,-1.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 1.0f}},
	{{-0.5f,  0.5f, -0.5f}, { 0.0f, 0.0f,-1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f}},
	{{-0.5f, -0.5f, -0.5f}, { 0.0f, 0.0f,-1.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
	{{-0.5f, -0.5f,  0.5f}, { 0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
	{{ 0.5f, -0.5f,  0.5f}, { 0.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
	{{ 0.5f,  0.5f,  0.5f}, { 0.0f, 0.0f, 1.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}},
	{{ 0.5f,  0.5f,  0.5f}, { 0.0f, 0.0f, 1.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}},
	{{-0.5f,  0.5f,  0.5f}, { 0.0f, 0.0f, 1.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},
	{{-0.5f, -0.5f,  0.5f}, { 0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
	{{-0.5f,  0.5f,  0.5f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
	{{-0.5f,  0.5f, -0.5f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 1.0f}},
	{{-0.5f, -0.5f, -0.5f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f}},
	{{-0.5f, -0.5f, -0.5f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f}},
	{{-0.5f, -0.5f,  0.5f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
	{{-0.5f,  0.5f,  0.5f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
	{{ 0.5f,  0.5f,  0.5f}, { 1.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
	{{ 0.5f,  0.5f, -0.5f}, { 1.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 1.0f}},
	{{ 0.5f, -0.5f, -0.5f}, { 1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f}},
	{{ 0.5f, -0.5f, -0.5f}, { 1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f}},
	{{ 0.5f, -0.5f,  0.5f}, { 1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
	{{ 0.5f,  0.5f,  0.5f}, { 1.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
	{{-0.5f, -0.5f, -0.5f}, { 0.0f,-1.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f}},
	{{ 0.5f, -0.5f, -0.5f}, { 0.0f,-1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 1.0f}},
	{{ 0.5f, -0.5f,  0.5f}, { 0.0f,-1.0f, 0.0f}, {1.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
	{{ 0.5f, -0.5f,  0.5f}, { 0.0f,-1.0f, 0.0f}, {1.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
	{{-0.5f, -0.5f,  0.5f}, { 0.0f,-1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
	{{-0.5f, -0.5f, -0.5f}, { 0.0f,-1.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f}},
	{{-0.5f,  0.5f, -0.5f}, { 0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f}},
	{{ 0.5f,  0.5f, -0.5f}, { 0.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 1.0f}},
	{{ 0.5f,  0.5f,  0.5f}, { 0.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
	{{ 0.5f,  0.5f,  0.5f}, { 0.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
	{{-0.5f,  0.5f,  0.5f}, { 0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
	{{-0.5f,  0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}, { 0.0f, 1.0f, 0.0f},{0.0f, 1.0f}} };

Vertex amphora0[24 * 24];

void GenerateAmphora(Vertex* const data, unsigned int rotCount, float innerRad, float middleRad, float outerRad, float h, const glm::vec3& col)
{
	for (unsigned int i{ 0 }; i < rotCount; i++)
	{
		float ang0 = glm::two_pi<float>() * i / (float)rotCount;
		float ang1 = glm::two_pi<float>() * (i+1) / (float)rotCount;
		glm::vec3 dir0{ cos(ang0), 0.0f, sin(ang0) };
		glm::vec3 dir1{ cos(ang1), 0.0f, sin(ang1) };
		unsigned int size = 24;
		glm::vec3 up(0.0f, 1.0f, 0.0f);

		float w{ outerRad - middleRad };

		// Inside
		data[size * i + 0] = { dir0 * innerRad, -dir0, col, glm::vec2(0.0f) };
		data[size * i + 1] = { dir1 * innerRad, -dir1, col, glm::vec2(0.0f) };
		data[size * i + 2] = { dir0 * innerRad + h * up, -dir0, col, glm::vec2(0.0f) };

		data[size * i + 3] = { dir1 * innerRad, -dir1, col, glm::vec2(0.0f) };
		data[size * i + 4] = { dir1 * innerRad + h * up, -dir1, col, glm::vec2(0.0f) };
		data[size * i + 5] = { dir0 * innerRad + h * up, -dir0, col, glm::vec2(0.0f) };

		// Top
		data[size * i + 6] = { dir0 * innerRad + h * up, up, col, glm::vec2(0.0f) };
		data[size * i + 7] = { dir1 * innerRad + h * up, up, col, glm::vec2(0.0f) };
		data[size * i + 8] = { dir0 * middleRad + h * up, up, col, glm::vec2(0.0f) };

		data[size * i + 9] =  { dir1 * middleRad + h * up, up, col, glm::vec2(0.0f) };
		data[size * i + 10] = { dir1 * innerRad + h * up, up, col, glm::vec2(0.0f) };
		data[size * i + 11] = { dir0 * middleRad + h * up, up, col, glm::vec2(0.0f) };

		// Slope
		data[size * i + 12] = { dir0 * outerRad, h*dir0 + w*up, col, glm::vec2(0.0f) };
		data[size * i + 13] = { dir1 * outerRad, h*dir1 + w*up, col, glm::vec2(0.0f) };
		data[size * i + 14] = { dir0 * middleRad + h * up, h*dir0+w*up, col, glm::vec2(0.0f)};

		data[size * i + 15] = { dir1 * outerRad, h*dir1 + w*up, col, glm::vec2(0.0f) };
		data[size * i + 16] = { dir1 * middleRad + h * up, h*dir1 + w*up, col, glm::vec2(0.0f) };
		data[size * i + 17] = { dir0 * middleRad + h * up, h*dir0 + w*up, col, glm::vec2(0.0f) };

		// Bottom
		data[size * i + 18] = { dir0 * innerRad, -up, col, glm::vec2(0.0f) };
		data[size * i + 19] = { dir1 * innerRad, -up, col, glm::vec2(0.0f) };
		data[size * i + 20] = { dir0 * outerRad, -up, col, glm::vec2(0.0f) };

		data[size * i + 21] = { dir1 * outerRad, -up, col, glm::vec2(0.0f) };
		data[size * i + 22] = { dir1 * innerRad, -up, col, glm::vec2(0.0f) };
		data[size * i + 23] = { dir0 * outerRad, -up, col, glm::vec2(0.0f) };
	}
}

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

static const unsigned int WINDOW_WIDTH = 1600;
static const unsigned int WINDOW_HEIGHT = 1200;


double currentTime = 0.0f;
double deltaTime = 0.0f;
float mouseX = WINDOW_WIDTH / 2;
float mouseY = WINDOW_HEIGHT / 2;
glm::vec3 lightColour = glm::vec3(1.0f, 1.0f, 1.0f);

DebugCamera debugCamera;

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	debugCamera.ApplyScrollControls((float)yoffset);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	float deltaX = xpos - mouseX;
	float deltaY = ypos - mouseY;

	mouseX = xpos;
	mouseY = ypos;

	debugCamera.ApplyLookControls(deltaX, deltaY);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		debugCamera.SetFOV(debugCamera.GetFOV() + 1.0f);
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		debugCamera.SetFOV(debugCamera.GetFOV() - 1.0f);
	}

	glm::vec3 camMoveVec(0.0f);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		camMoveVec.z -= 1.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		camMoveVec.z += 1.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		camMoveVec.x -= 1.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		camMoveVec.x += 1.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		camMoveVec.y += 1.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		camMoveVec.y -= 1.0f;
	}

	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
	{
		lightColour.r = fmod(lightColour.r + 0.05f, 1.0f);
	}

	if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
	{
		lightColour.g = fmod(lightColour.g + 0.05f, 1.0f);
	}

	if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
	{
		lightColour.b = fmod(lightColour.b + 0.05f, 1.0f);
	}
	debugCamera.ApplyMoveControls(camMoveVec.x, camMoveVec.y, camMoveVec.z, deltaTime);
}


int main(int argc, const char** argv)
{
	debugCamera.PreApplyTranslation(glm::vec3(0.0f, 0.0f, 3.0f));
	debugCamera.SetAspectRatio((float)WINDOW_WIDTH / (float)WINDOW_HEIGHT);
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

	GenerateAmphora(amphora0, 24, 0.8f, 1.0f, 1.1f, 0.2f, glm::vec3(1.0f));
	
	//glBindTexture(GL_TEXTURE_2D, 0);

	//Shader shader("shader.vs", "shader.fs");
	Shader lightingShader("shader.vs", "lightingShader.fs");
	Shader lightShader("shader.vs", "lightShader.fs");

	glm::mat4 trans = glm::mat4(1.0f); // Identity
	glm::mat4 view = glm::mat4(1.0f); // Identity
	glm::vec3 lightPos = glm::vec3(1.0);

	Mesh mesh(amphora0, sizeof(amphora0) / sizeof(Vertex));
	Mesh lightMesh(vertices, sizeof(vertices) / sizeof(Vertex));

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		glfwSwapBuffers(window);
		glm::mat4 proj;
		debugCamera.GetProjectionMatrix(proj);

		glClearColor(0.1f, 0.15f, 0.15f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		lightingShader.Use();
		deltaTime = glfwGetTime() - currentTime;
		currentTime = glfwGetTime();
		lightPos = glm::vec3(3.5f * cos(currentTime), 1.5f, 3.5f * sin(currentTime));
		//lightingShader.SetUniformFloat("time", currentTime);
		
		debugCamera.GetViewMatrix(view);
		lightingShader.SetUniformMat4("view", view);
		lightingShader.SetUniformMat4("proj", proj);
		

		//shader.SetUniformInt("ourTexture0", 0);
		//shader.SetUniformInt("ourTexture1", 1);
		//tex0.SetToTextureUnit(0);
		//tex1.SetToTextureUnit(1);
		lightingShader.SetUniformVec3("light.position", view * glm::vec4(lightPos,1.0f));
		lightingShader.SetUniformVec3("light.ambient", 0.1f * lightColour);
		lightingShader.SetUniformVec3("light.diffuse", 0.8f * lightColour);
		lightingShader.SetUniformVec3("light.specular", glm::vec3(0.8f, 0.8f, 0.1f) * lightColour);

		mesh.BindMesh();

		// Cubes
		for (unsigned int i = 0; i < sizeof(positions) / sizeof(positions[0]); i++)
		{
			trans = glm::mat4(1.0f);
			trans = glm::translate(trans, positions[i]);
			trans = glm::rotate(trans, glm::radians(20.0f * i), glm::vec3(1.0f));
			trans = glm::scale(trans, glm::vec3(1.0f));

			lightingShader.SetUniformMat4("model", trans);
			glm::mat3 normalMat = glm::mat3(glm::transpose(glm::inverse(trans)));
			lightingShader.SetUniformMat3("normMat", normalMat);

			glm::vec3 col = glm::vec3(0.5f * abs(sin(i)), 0.3f * abs(cos(i)), 0.5f * abs(sin(3*i)));

			lightingShader.SetUniformVec3("material.ambient", col);
			lightingShader.SetUniformVec3("material.diffuse", col);
			lightingShader.SetUniformVec3("material.specular", col);
			lightingShader.SetUniformFloat("material.shininess", 0.5f);

			glDrawArrays(GL_TRIANGLES, 0, sizeof(amphora0)/sizeof(Vertex));
		}

		// Light
		glm::mat4 transLight = glm::mat4(1.0f); // Identity
		transLight = glm::translate(transLight, lightPos);
		transLight = glm::scale(transLight, glm::vec3(0.2f));
		lightShader.Use();
		lightShader.SetUniformMat4("view", view);
		lightShader.SetUniformMat4("proj", proj);
		lightShader.SetUniformMat4("model", transLight);
		lightShader.SetUniformVec3("lightColour", lightColour);

		lightMesh.BindMesh();
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(unsigned int), GL_UNSIGNED_INT, 0);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}