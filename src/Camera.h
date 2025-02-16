#pragma once
#include "Singleton.h"
#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "Actions.h"

class Camera : public Singleton<Camera>
{
public:
	inline const glm::vec3 GetPosition() { return m_pos; }
	inline const glm::vec3 GetForward() { return m_forwardVector; }
	inline const glm::mat4 GetViewMatrix() { return m_lookAtMat;}
	inline void SetPosition(const glm::vec3& pos) { m_pos = pos; }
	const glm::vec3 GET_RIGHT();
	void MoveCamera(InputSystem::Action action);
	void Update();

private:
	friend class Singleton<Camera>;
	Camera();
	glm::vec3 m_pos;
	glm::vec3 m_forwardVector;
	glm::vec3 m_upVector;
	glm::mat4 m_lookAtMat;
	float m_movementSpeed;
};