#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <iostream>

#include "App.h"
#include "AppConfig.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	App* app = new App();
	GLFWwindow* window = app->CreateAppWindow();

	if (window == nullptr)
	{
		std::cout << "Failed to initialise Opengl Window" << std::endl;
		delete app;
		return -1;
	}
	
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		delete app;
		return -1;
	}

	glViewport(0, 0,Config::WINDOW::SCREEN_WIDTH, Config::WINDOW::SCREEN_HEIGHT);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	app->Init();

	while (!glfwWindowShouldClose(window))
	{
		
		app->ProcessInput();
		app->Render();
		app->Update();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwMakeContextCurrent(NULL);
	delete app;
	glfwTerminate();
	return 1;
}


