#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include <iostream>
#include <string>
#include <fstream>
#include <thread>

#include "vertexBuffer.h"
#include "indexBuffer.h"
#include "shader.h"

#ifdef DEBUG_M
#define LOG(x) std::cout << "DEBUG | "  << x << std::endl;
#else
#define LOG(X)
#endif

#define BUFFER_OFFSET(offset) (static_cast<char*>(0) + (offset))

static float scale = 1.0f, offsetX = 0.0f, offsetY = 0.0f, beforeX, beforeY, afterX, afterY;
static double xpress, ypress, x, y, previous_x, previous_y;
static glm::vec3 translation(0, 0, 0);
static bool lbutton_down = false;

template<typename T>
void readData(const std::string& filepath, T array[],const char* stringTo)
{
	int i = 0;
	std::ifstream file;
	file.open(filepath);
	std::string line;
	while (std::getline(file, line))
	{
		if ("float" == stringTo)
			array[i] = std::stof(line);
		else if ("unsigned" == stringTo)
			array[i] = std::stoul(line);
		else if ("int" == stringTo)
			array[i] = std::stoi(line);
		i++;
	}
}

void readOffset(const std::string& filepath, char* array[])
{
	int i = 0;
	std::ifstream file;
	file.open(filepath);
	std::string line;
	while (std::getline(file, line))
	{
		array[i] = BUFFER_OFFSET(std::stoul(line) * sizeof(GLuint));
		i++;
	}
}


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (lbutton_down)
	{
		LOG("X moved: " << (previous_x - xpos) << " Y moved: " << (previous_y - ypos));
		offsetX = previous_x - xpos;
		offsetY = previous_y - ypos;
		translation.x -= offsetX;
		translation.y += offsetY;
		previous_x = xpos;
		previous_y = ypos;
	}
}

static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		glfwGetCursorPos(window, &previous_x, &previous_y);
		lbutton_down = true;
		LOG("Cursor Pressed at " << previous_x  << " : " << previous_y);
	}
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		lbutton_down = false;
		glfwGetCursorPos(window, &x, &y);
		LOG("Cursor Released at " << x << " : " << y);
	}
}
/*
void worldToScreen(float worldX, float worldY, int& screenX, int& screenY)
{
	screenX = (int)((worldX - offsetX) * scale);
	screenY = (int)((worldY - offsetY) * scale);
}

void screenToWorld(int screenX, int screenY, float& worldX, float& worldY)
{
	worldX = (float)((screenX) / scale) + offsetX;
	worldY = (float)((screenY) / scale) + offsetY;
	LOG("worldX " << worldX << "worldY " << worldY);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	glfwGetCursorPos(window, &x, &y);
	//screenToWorld(x, y, beforeX, beforeY);

	beforeX = (float)((x) / scale) + offsetX;
	beforeY = (float)((y) / scale) + offsetY;

	if (yoffset == 1.0)
	{
		scale *= 1.01f;
		LOG(scale << " zoom out");
	}
	if (yoffset == -1.0)
	{
		scale *= 0.99f;
		LOG(scale << "zoom in");
	}
	
	//afterX = x * scale;
	//afterY = y * scale;
	//offsetX = (beforeX - afterX);
	//offsetY = (beforeY - afterY);
	//translation.x -= offsetX;
	//translation.y += offsetY;
	//glfwGetCursorPos(window, &x, &y);
	
	//screenToWorld(x, y, afterX, afterY);
	afterX = (float)((x) / scale) + offsetX;
	afterY = (float)((y) / scale) + offsetY;
	offsetX = (beforeX - afterX);
	offsetY = (afterY - beforeY);
	translation.x += offsetX;
	translation.y += offsetY;
}
*/

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_SAMPLES, 4);
	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1280, 720, "...", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	glEnable(GL_MULTISAMPLE);

	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	//glfwSetScrollCallback(window, scroll_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
		return -1;
	
	float* vertexArray = new float[119072];
	std::thread rVertex(readData<float>,"src/point.txt", vertexArray, "float");
	
	unsigned int* indexArray = new unsigned int[119072];
	std::thread rIndex(readData<unsigned int>, "src/index.txt", indexArray, "unsigned");
	
	GLsizei* countArray = new GLsizei[8854];
	std::thread rCount(readData<int>, "src/count.txt", countArray, "int");
	
	char** offset = new char*[8854];
	std::thread rOffset(readOffset, "src/offset.txt", offset);

	rVertex.join();
	rIndex.join();
	rCount.join();
	rOffset.join();

	vertexBuffer vb(vertexArray, 119072 * 2 * sizeof(float));

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

	indexBuffer ib(indexArray, 119072);
	
	shader defaultShader("src/default.shader");
	defaultShader.use();
	
	ImVec4 clear_color = ImVec4(0.752f, 0.752f, 0.752f, 1.0f);
	ImVec4 line_color = ImVec4(0.2f, 0.5f, 0.8f, 1.0f);
	int width = 3;

	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330 core");
	ImGui::StyleColorsDark();

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		/* Render here */
		glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);

		glm::mat4 proj = glm::ortho(474198409.0f, 476454687.0f, 213569142.0f, 218833644.0f, -1.0f, 1.0f);
		glm::mat4 view = glm::translate(glm::mat4(1.0f), translation);
		//glm::mat4 model = glm::translate(glm::mat4(1.0f), translation);
		glm::mat4 mvp = proj * view;// * model;
		glUniformMatrix4fv(glGetUniformLocation(defaultShader.getId(), "u_MVP"), 1, GL_FALSE, &mvp[0][0]);
		defaultShader.setUniform("u_Color", line_color.x, line_color.y, line_color.z, line_color.w);

		glLineWidth(width);
		//for (int i = 0; i < 6; i++)
		//glDrawElements(GL_LINE_STRIP, 8, GL_UNSIGNED_INT, nullptr);
		glMultiDrawElements(GL_LINE_STRIP, countArray, GL_UNSIGNED_INT, (const void**)offset, 8854);
		//glDrawArrays(GL_LINE_STRIP, indexes[i++], indexes[i]);

		ImGui::Begin("imgui");                          // Create a window called "Hello, world!" and append into it.
		if (ImGui::IsAnyItemHovered() | ImGui::IsWindowHovered())
			lbutton_down = false;

		//ImGui::Text("");               // Display some text (you can use a format strings too)
		ImGui::Checkbox("lbutton_down", &lbutton_down);
		ImGui::SliderInt("line width", &width, 1, 10);
		//ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
		ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color
		ImGui::ColorEdit3("line color", (float*)&line_color);
		/*
		if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
			counter++;
		ImGui::SameLine();
		ImGui::Text("counter = %d", counter);
		*/

		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	delete[] vertexArray;
	delete[] indexArray;
	delete[] countArray;
	delete[] offset;
	glfwTerminate();
	return 0;
}