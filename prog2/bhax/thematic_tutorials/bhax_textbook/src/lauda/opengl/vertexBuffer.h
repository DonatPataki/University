#pragma once

class vertexBuffer
{
private:
	unsigned int id;
public:
	vertexBuffer(const void* data, unsigned int size);
	~vertexBuffer();
	void bind();
	void unbind();
};