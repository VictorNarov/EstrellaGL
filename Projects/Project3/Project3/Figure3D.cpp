
#include "stdafx.h"
#include <glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Figure3D.h"

Figure3D::~Figure3D()
{
	if (vertices != NULL) delete[] vertices;
	if (indexes != NULL) delete[] indexes;

	// Delete vertex buffer objects
	glDeleteBuffers(2, VBO);
}

void Figure3D::InitBuffers()
{
	// Create the Vertex Array Object
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// Create the Vertex Buffer Objects
	glGenBuffers(2, VBO);

	// Copy data to video memory
	// Vertex data
	glBindBuffer(GL_ARRAY_BUFFER, VBO[VERTEX_DATA]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*numVertices * 3, vertices, GL_STATIC_DRAW);

	// Indexes
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO[INDEX_DATA]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLushort)*numFaces * 3, indexes, GL_STATIC_DRAW);

	delete[] vertices;
	delete[] indexes;

	vertices = NULL;
	indexes = NULL;

	glEnableVertexAttribArray(0); // Vertex position
	glBindBuffer(GL_ARRAY_BUFFER, VBO[VERTEX_DATA]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
}

void Figure3D::ResetLocation()
{
	location = glm::mat4(1.0f);
}

void Figure3D::Translate(glm::vec3 t)
{
	location = glm::translate(location, t);
}

void Figure3D::Rotate(GLfloat angle, glm::vec3 axis)
{
	location = glm::rotate(location, glm::radians(angle), axis);
}

void Figure3D::Draw(ShaderProgram* program, glm::mat4 projection, glm::mat4 view)
{
	glm::mat4 mvp = projection * view * location;
	program->SetUniformMatrix4("MVP", mvp);

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, numFaces * 3, GL_UNSIGNED_SHORT, NULL);
}

