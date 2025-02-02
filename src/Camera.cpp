#include "Camera.h"

void Camera::Init()
{
	m_pos = glm::vec3(0.0f, 0.0f, -3.0f);
	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	m_direction = glm::normalize(cameraTarget - m_pos);
	glm::vec3 upVector = glm::vec3(0.0f, 0.1f, 0.0f);
	m_rightVector = glm::normalize(glm::cross(m_direction, upVector));
	m_upVector = glm::cross(m_rightVector, m_direction);
}