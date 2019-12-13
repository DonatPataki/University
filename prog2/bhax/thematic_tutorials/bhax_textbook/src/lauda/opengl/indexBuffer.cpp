#include "indexBuffer.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

indexBuffer::indexBuffer(const unsigned int* data, unsigned int elementCount)
	:elementCount(elementCount)
{
	glGenBuffers(1, &id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, elementCount * sizeof(GLuint), data, GL_STATIC_DRAW);
}

indexBuffer::~indexBuffer()
{
	glDeleteBuffers(1, &id);
}

void indexBuffer::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void indexBuffer::unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
