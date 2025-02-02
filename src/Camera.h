#pragma once
#include <glm.hpp>
#include "Singleton.h"

class Camera : public Singleton<Camera>
{

public:
	const glm::vec3 GetPosition();
	const glm::vec3 GetDirection();
	void SetPosition(glm::vec3& pos);
	void SetDirection(glm::vec3& dir);
	void Init();

private:
	Camera();
	glm::vec3 m_pos;
	glm::vec3 m_direction;
	glm::vec3 m_upVector;
	glm::vec3 m_rightVector;
};