#pragma once

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 colour;
	glm::vec2 uv;
};

class Mesh
{
public:
	Mesh(const Vertex* data, unsigned int vertexCount);

	void BindMesh();
private:
	unsigned int vaoId;
};