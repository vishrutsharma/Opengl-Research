#pragma once
#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <vector>


extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const char* WINDOW_TITLE;

class Mesh;

class App
{

public:
	App();
	~App();


	GLFWwindow* CreateAppWindow();
	void Init();
	void ProcessInput();
	void Render();
	void Update();

private:
	GLFWwindow* m_window = nullptr;
	std::vector<Mesh*> m_meshes;

};