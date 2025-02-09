#pragma once
#include "Singleton.h"
#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

class Camera : public Singleton<Camera>
{
public:
	inline const glm::vec3 GetPosition() { return m_pos; }
	inline const glm::vec3 GetForward() { return m_direction; }
	inline const glm::vec3 GetRight() { return m_rightVector; }
	inline const glm::vec3 GetUp() { return m_upVector; }
	inline const glm::mat4 GetViewMatrix() { return m_lookAtMat;}
	inline void SetPosition(const glm::vec3& pos) { m_pos = pos; }

	void Update();

private:
	friend class Singleton<Camera>;
	Camera();
	glm::vec3 m_pos;
	glm::vec3 m_direction;
	glm::vec3 m_upVector;
	glm::vec3 m_rightVector;
	glm::mat4 m_lookAtMat;
};