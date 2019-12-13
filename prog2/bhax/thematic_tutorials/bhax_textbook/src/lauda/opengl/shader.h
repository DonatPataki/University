#pragma once

#include <string>

static std::string vertexShader;
static std::string fragmentShader;

class shader
{
private:
	unsigned int id;
public:
	shader(const std::string& filepath);
	~shader();
	void use();
	void setUniform(const std::string& name, float v0, float v1, float v2, float v3);
	unsigned int getId();
private:
	void readShader(const std::string& filepath, std::string& vetexShader, std::string& fragmentShader);
	unsigned int compileShader(unsigned int type, const std::string& source);
	unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);
	int getUniformLocation(const std::string& name);
};