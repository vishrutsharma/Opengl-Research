#pragma once
#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include "InputManager.h"
#include "KeyBindings.h"
#include <vector>
#include "GameObject.h"
#include "BaseObject.h"

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

	std::vector<GameObject*> m_gameObjects;
	GameObject* m_light;
	int m_framesSampleCount;
	int m_frames;
	float m_elapsedTime;
	int m_lastMouseXPos;
	int m_lastMouseYPos;
	float m_mouseYaw;
	float m_mousePitch;

};