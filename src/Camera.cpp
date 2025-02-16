#include "Camera.h"
#include <iostream>
#include "Time.h"

 Camera::Camera(): 
	 m_movementSpeed(10.05f), 
	 m_pos(glm::vec3(0.0f, 0.0f, -3.0f)),
	 m_forwardVector(glm::vec3(0.0f, 0.0f, -1.0f)),
	 m_upVector(glm::vec3(0.0f, 1.0f, 0.0f))
{
	m_lookAtMat = glm::lookAt(m_pos, m_pos+m_forwardVector,m_upVector);
}

 void Camera::Update()
 {
	 m_lookAtMat = glm::lookAt(m_pos, m_pos+m_forwardVector, m_upVector);
 }

void Camera::MoveCamera(InputSystem::Action action)
{
	switch (action)
	{
		case InputSystem::Action::MOVE_FORWARD:
			m_pos += (m_movementSpeed*Time::GetInstance().GetDeltaTime()) * m_forwardVector;
			break;

		case InputSystem::Action::MOVE_BACKWARD:
			m_pos -= (m_movementSpeed * Time::GetInstance().GetDeltaTime()) * m_forwardVector;
			break;

		case InputSystem::Action::MOVE_LEFT:
			m_pos -= (m_movementSpeed * Time::GetInstance().GetDeltaTime()) * GET_RIGHT();
			break;

		case InputSystem::Action::MOVE_RIGHT:
			m_pos += (m_movementSpeed * Time::GetInstance().GetDeltaTime()) * GET_RIGHT();
			break;

	}
}

const glm::vec3 Camera::GET_RIGHT()
{
	return glm::normalize(glm::cross(m_forwardVector, m_upVector));
}