#include "InputManager.h"
using namespace InputSystem;

#include <iostream>

InputManager::InputManager(GLFWwindow* window) :m_window(window),m_mouseXPos(0),m_mouseYPos(0)
{
	glfwSetKeyCallback(m_window, KeyCallback);
	glfwSetMouseButtonCallback(m_window, MouseButtonCallback);
	glfwSetCursorPosCallback(m_window, CursorPositionCallback);
}

void InputManager::Update()
{
	/*for (auto& [key,state] : m_keyStates)
	{
		m_prevStates[key] = state;
	}*/
}

bool InputManager::IsKeyPressed(int keyCode)
{
	return m_keyStates[keyCode] && !m_prevStates[keyCode];
}

bool InputManager::IsKeyHeld(int keyCode)
{
	return m_keyStates[keyCode];
}

bool InputManager::IsKeyReleased(int keyCode)
{
	return !m_keyStates[keyCode] && m_prevStates[keyCode];
}

bool InputManager::IsMouseButtonPressed(int button)
{
	return m_mouseButtonStates[button];
}

void InputManager::GetMousePosition(int& x,int& y)
{
	x = m_mouseXPos;
	y = m_mouseYPos;
}


void InputManager::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    InputManager* input = static_cast<InputManager*>(glfwGetWindowUserPointer(window));
    if (!input) return;

    if (action == GLFW_PRESS)
    {
        input->m_keyStates[key] = true;
    }
    else if (action == GLFW_RELEASE)
    {
        input->m_keyStates[key] = false;
    }
}

void InputManager::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    InputManager* input = static_cast<InputManager*>(glfwGetWindowUserPointer(window));
    if (!input) return;

    if (action == GLFW_PRESS)
        input->m_mouseButtonStates[button] = true;
    else if (action == GLFW_RELEASE)
        input->m_mouseButtonStates[button] = false;
}

void InputManager::CursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
    InputManager* input = static_cast<InputManager*>(glfwGetWindowUserPointer(window));
    if (!input) return;

    input->m_mouseXPos = xpos;
    input->m_mouseYPos = ypos;
}
