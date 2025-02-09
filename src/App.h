#pragma once
#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include "InputManager.h"
#include "KeyBindings.h"
#include <vector>

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
	InputManager* m_inputManager = nullptr;
	KeyBindings* m_keyBindings = nullptr;

	std::vector<Mesh*> m_meshes;

};