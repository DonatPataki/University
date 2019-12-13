#pragma once

class indexBuffer
{
private:
	unsigned int id;
	unsigned int elementCount;
public:
	indexBuffer(const unsigned int* data, unsigned int elementNumber);
	~indexBuffer();
	void bind();
	void unbind();
};