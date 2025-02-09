#pragma once

#include <GLFW\glfw3.h>
#include <glad\glad.h>
#include <unordered_map>

namespace InputSystem
{
	class InputManager
	{
	public:
		InputManager(GLFWwindow*);
		bool IsKeyPressed(int);
		bool IsKeyReleased(int);
		bool IsKeyHeld(int);
		bool IsMouseButtonPressed(int);
		void Update();
		void GetMousePosition(int& x, int& y);

	private:
		static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);


		GLFWwindow* m_window;
		std::unordered_map<int, bool> m_keyStates;
		std::unordered_map<int, bool> m_prevStates;
		std::unordered_map<int, bool> m_mouseButtonStates;
		double m_mouseXPos, m_mouseYPos;
	};
}