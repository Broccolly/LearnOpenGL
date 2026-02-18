#pragma once

class Shader
{
public:
	unsigned int ID{ 0 };

	// Constructor
	Shader(const char* vertexPath, const char* fragmentPath);

	// Activate shader
	void Use();

	void SetUniformBool(const std::string& name, bool value) const;
	void SetUniformInt(const std::string& name, int value) const;
	void SetUniformFloat(const std::string& name, float value) const;
	void SetUniformVec3(const std::string& name, const glm::vec3& value) const;
	void SetUniformMat3(const std::string& name, const glm::mat3& value) const;
	void SetUniformMat4(const std::string& name, const glm::mat4& value) const;
};