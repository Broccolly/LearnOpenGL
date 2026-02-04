#include <iostream>
#include <fstream>
#include <sstream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	// Read vertex code
	vShaderFile.open(vertexPath);
	std::stringstream vShaderStream;
	vShaderStream << vShaderFile.rdbuf();
	vShaderFile.close();
	vertexCode = vShaderStream.str();
	const char* pvShaderCode = vertexCode.c_str();

	// Read fragment code
	fShaderFile.open(fragmentPath);
	std::stringstream fShaderStream;
	fShaderStream << fShaderFile.rdbuf();
	fShaderFile.close();
	fragmentCode = fShaderStream.str();
	const char* pfShaderCode = fragmentCode.c_str();

	// Construct shader program
	unsigned int vertex;
	unsigned int fragment;
	int success;
	char infoLog[512];

		// Compile vertex shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &pvShaderCode, NULL);
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "ERROR::SAHADER::VERTEX::COMPILATION FAILED\n" << infoLog << std::endl;
	}

		// Compile fragment shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &pfShaderCode, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		std::cout << "ERROR::SAHADER::VERTEX::COMPILATION FAILED\n" << infoLog << std::endl;
	}

	ID = glCreateProgram();
	glAttachShader(ID,vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);

	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER_PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::Use()
{
	glUseProgram(ID);
}

void Shader::SetUniformBool(const std::string& name, bool value) const
{
	int loc = glGetUniformLocation(ID, name.c_str());
	if (loc >= 0)
	{
		glUniform1i(loc, (int)value);
	}
}

void Shader::SetUniformInt(const std::string& name, int value) const
{
	int loc = glGetUniformLocation(ID, name.c_str());
	if (loc >= 0)
	{
		glUniform1i(loc, value);
	}
}

void Shader::SetUniformFloat(const std::string& name, float value) const
{
	int loc = glGetUniformLocation(ID, name.c_str());
	if (loc >= 0)
	{
		glUniform1f(loc, value);
	}
}