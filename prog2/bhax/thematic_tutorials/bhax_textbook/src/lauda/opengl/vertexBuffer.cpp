#include "vertexBuffer.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

vertexBuffer::vertexBuffer(const void* data, unsigned int size)
{
	glGenBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

vertexBuffer::~vertexBuffer()
{
	glDeleteBuffers(1, &id);
}

void vertexBuffer::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void vertexBuffer::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
