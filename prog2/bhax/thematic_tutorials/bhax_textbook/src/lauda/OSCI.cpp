#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include <math.h>

static float angle = 0.0f;
static glm::vec3 translation(0, 0, 0);

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	if (key == GLFW_KEY_W)
	{
		std::cout << "w\n";
		translation.x += sin(angle) * 0.01f;
		translation.y += cos(angle) * 0.01f;
	}

	if (key == GLFW_KEY_S )
	{
		std::cout << "s\n";
		translation.x -= sin(angle) * 0.01f;
		translation.y -= cos(angle) * 0.01f;
	}

	if (key == GLFW_KEY_D)
	{
		std::cout << "d\n";
		angle -= 5.0f;
	}

	if (key == GLFW_KEY_A)
	{
		std::cout << "a\n";
		angle += 5.0f;
	}
}

static unsigned int compileShader(unsigned int type, const std::string& source)
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

static unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader)
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

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;


	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "OSCI", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwSetKeyCallback(window, key_callback);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
		return -1;

	float positions[] = {
		-0.5f, -0.5f,
		 0.5f,  -0.5f,
		 0.5f, 0.5f,
		 -0.5f, 0.5f,
	};

	unsigned int indices[] = {
		0, 1, 2, 2, 3, 0
	};

	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * 2 *sizeof(float), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

	unsigned int ibo;
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6  * sizeof(unsigned int), indices, GL_STATIC_DRAW);


	std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;\n"
		"uniform mat4 u_MVP;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	gl_Position = u_MVP * position;\n"
		"}\n";

	std::string fragmentShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 color;"
		"\n"
		"void main()\n"
		"{\n"
		"	color = vec4(1.0, 0.0, 0.0, 1.0);\n"
		"}\n";
	unsigned int shader = createShader(vertexShader, fragmentShader);
	glUseProgram(shader);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glm::mat4 model = glm::translate(glm::mat4(1.0f), translation);
		model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
		glm::mat4 mvp =  model;
		glUniformMatrix4fv(glGetUniformLocation(shader, "u_MVP"), 1, GL_FALSE, &mvp[0][0]);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glDeleteProgram(shader);

	glfwTerminate();
	return 0;
}
