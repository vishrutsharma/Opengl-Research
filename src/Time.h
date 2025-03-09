#pragma once
#include <GLFW/glfw3.h>
#include "Singleton.h"

class Time : public Singleton<Time>
{
	public:
		inline float GetDeltaTime() { return m_deltaTime; }
		inline float GetCurrentTime() { return glfwGetTime(); }
		void Update();

	private:
		friend class Singleton<Time>;
		Time();

		float m_lastTime;
		float m_deltaTime;
		float m_timeSinceStart;
};