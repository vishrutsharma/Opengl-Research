#include "Camera.h"
#include <iostream>

 Camera::Camera()
{
	std::cout << "Cosntructor of camera called" << std::endl;
	m_pos = glm::vec3(0.0f, 0.0f, -3.0f);
	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	m_direction = glm::normalize(cameraTarget - m_pos);
	glm::vec3 upVector = glm::vec3(0.0f, 0.1f, 0.0f);
	m_rightVector = glm::normalize(glm::cross(m_direction, upVector));
	m_upVector = glm::cross(m_rightVector, m_direction);
	m_lookAtMat = glm::lookAt(m_pos, m_direction, m_upVector);
}

void Camera::Update()
{
	std::cout << "Here in yupodate:" << std::endl;
	const float radius = 20.0f;
	float xPos = glm::sin(glfwGetTime()) * radius;
	float zPos = glm::cos(glfwGetTime()) * radius;
	m_lookAtMat = glm::lookAt(glm::vec3(xPos, 0, zPos), m_direction, m_upVector);
}