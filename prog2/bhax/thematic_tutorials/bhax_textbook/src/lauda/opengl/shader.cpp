#include "shader.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <iostream>

shader::shader(const std::string& filepath)
	:id(0)
{
	readShader(filepath, vertexShader, fragmentShader);
	id = createShader(vertexShader, fragmentShader);
}

shader::~shader()
{
	glDeleteProgram(id);
}

void shader::readShader(const std::string& filepath, std::string& vetexShader, std::string& fragmentShader)
{
	std::ifstream file;
	file.open(filepath);
	std::string line;
	std::string vertexS = "", fragmentS = "";
	char type = '0';
	while (std::getline(file, line))
	{
		if (line.find("S_BEGIN") != std::string::npos)
		{
			if (line.find("VERTEX") != std::string::npos)
			{
				type = 'v';
			}
			else
			{
				type = 'f';
			}
		}
		else
		{
			if (type == 'v')
			{
				vertexS += line;
				vertexS += "\n";
			}
			else if (type == 'f')
			{
				fragmentS += line;
				fragmentS += "\n";
			}
		}
	}
	vetexShader = vertexS;
	fragmentShader = fragmentS;
}

unsigned int shader::compileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = &source[0];
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "error" << (type == GL_VERTEX_SHADER ? " vertex" : " fragment") << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}

unsigned int shader::createShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);
	glDeleteShader(vs);
	glDeleteShader(fs);

		return program;
}

void shader::use()
{
	glUseProgram(id);
}

void shader::setUniform(const std::string& name, float v0, float v1, float v2, float v3)
{
	glUniform4f(getUniformLocation(name), v0, v1, v2, v3);
}

int shader::getUniformLocation(const std::string& name)
{
	int location = glGetUniformLocation(id, name.c_str());
	return location;
}

unsigned int shader::getId()
{
	return id;
}