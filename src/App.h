#pragma once
#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include "InputManager.h"
#include "KeyBindings.h"
#include <vector>

class Mesh;

using namespace InputSystem;

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
	void CalculateFPS();

private:
	GLFWwindow* m_window = nullptr;

	InputManager* m_inputManager = nullptr;
	KeyBindings* m_keyBindings = nullptr;

	std::vector<Mesh*> m_meshes;
	int m_framesSampleCount;
	int m_frames;
	float m_elapsedTime;

};