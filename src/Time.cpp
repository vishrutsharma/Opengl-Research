#include "Time.h"

Time::Time() : m_deltaTime(0.0f), m_timeSinceStart(0.0f), m_lastTime(0.0f) {}

void Time::Update()
{
	float currentTime = GetCurrentTime();
	m_deltaTime = currentTime - m_lastTime;
	m_lastTime = currentTime;
}