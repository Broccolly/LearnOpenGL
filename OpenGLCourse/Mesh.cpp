#include <glm/glm.hpp>
#include <glad/glad.h>
#include "Mesh.h"

Mesh::Mesh(const Vertex* data, unsigned int vertexCount)
{
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	vaoId = VAO;

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(Vertex), reinterpret_cast<const float*>(data), GL_STATIC_DRAW);

	unsigned int offset = 0;
	glVertexAttribPointer(0, sizeof(Vertex::position)/sizeof(float), GL_FLOAT, GL_FALSE,  sizeof(Vertex), (void*)offset);
	glEnableVertexAttribArray(0);
	offset += sizeof(Vertex::position);

	glVertexAttribPointer(1, sizeof(Vertex::normal) / sizeof(float), GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offset);
	glEnableVertexAttribArray(1);
	offset += sizeof(Vertex::normal);

	glVertexAttribPointer(2, sizeof(Vertex::colour) / sizeof(float), GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offset);
	glEnableVertexAttribArray(2);
	offset += sizeof(Vertex::colour);

	glVertexAttribPointer(3, sizeof(Vertex::uv) / sizeof(float), GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offset);
	glEnableVertexAttribArray(3);

	glBindVertexArray(0);
}

void Mesh::BindMesh()
{
	glBindVertexArray(vaoId);
}
