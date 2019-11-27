#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;


	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "OSCI3", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
		return -1;

	float positions[] = {
		-0.5f, -0.5f,
		 0.5f,  0.5f,
		 0.3f, 0.4f,
		 1.0f, 1.0f,
		 0.2f, -0.4f,
		 -0.9f, -0.8f,
		 -0.7f, 0.0f,
		 0.2f, 0.0f
	};

	unsigned int indexes[] = {0, 2, 2, 2, 5, 4};
		

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(2, GL_FLOAT, 0, positions);
			glDrawArrays(GL_LINE_STRIP, indexes[0], indexes[1]);
			glDrawArrays(GL_LINE_STRIP, indexes[2], indexes[3]);
			glDrawArrays(GL_LINE_STRIP, indexes[4], indexes[5]);
		glDisableClientState(GL_VERTEX_ARRAY);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}


	glfwTerminate();
	return 0;
}
