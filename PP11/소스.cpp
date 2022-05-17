#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

#pragma comment(lib,"OpenGL32")
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

float X_1 = 0.5;
float X_2 = 0.8;
float X_3 = 0.8;
float X_4 = 0.5;
float X_5 = 0.5;
float X_6 = 0.8;

float y_1 = 0.3;
float y_2 = 0.3;
float y_3 = 0.0;
float y_4 = 0.0;
float y_5 = 0.3;
float y_6 = 0.0;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
		y_1 = y_1 + 0.1;
		y_2 = y_2 + 0.1;
		y_3 = y_3 + 0.1;
		y_4 = y_4 + 0.1;
		y_5 = y_5 + 0.1;
		y_6 = y_6 + 0.1;
	}
	if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
		y_1 = y_1 - 0.1;
		y_2 = y_2 - 0.1;
		y_3 = y_3 - 0.1;
		y_4 = y_4 - 0.1;
		y_5 = y_5 - 0.1;
		y_6 = y_6 - 0.1;
	}
	if (key == GLFW_KEY_LEFT && action == GLFW_PRESS) {
		X_1 = X_1 - 0.1;
		X_2 = X_2 - 0.1;
		X_3 = X_3 - 0.1;
		X_4 = X_4 - 0.1;
		X_5 = X_5 - 0.1;
		X_6 = X_6 - 0.1;
	}
	if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) {
		X_1 = X_1 + 0.1;
		X_2 = X_2 + 0.1;
		X_3 = X_3 + 0.1;
		X_4 = X_4 + 0.1;
		X_5 = X_5 + 0.1;
		X_6 = X_6 + 0.1;
	}
}

int main()
{
	

	GLFWwindow* window;
	if (!glfwInit())
		exit(EXIT_FAILURE);
	window = glfwCreateWindow(800, 800, "Simple example", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	while (!glfwWindowShouldClose(window))
	{
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float)height;

		glClearColor(0.0f,0.0f,0.0f,1);
		glClear(GL_COLOR_BUFFER_BIT);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);

		glBegin(GL_TRIANGLES);
		glColor3f(1,0,0);
		glVertex2f(0.0, 0.3);
		glVertex2f(0.3, 0.3);
		glVertex2f(0.3, 0.0);
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 0.3);
		glVertex2f(0.3, 0.0);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0, 1, 0);
		glVertex2f(X_1, y_1);
		glVertex2f(X_2, y_2);
		glVertex2f(X_3, y_3);
		glVertex2f(X_4, y_4);
		glVertex2f(X_5, y_5);
		glVertex2f(X_6, y_6);
		glEnd();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}