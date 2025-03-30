#include "GameObject.h"
#include "Time.h"

GameObject::GameObject(std::string name) : BaseObject(name) {}

void GameObject::Update()
{
	BaseObject::Update();
	if (!isLightCaster)
	{
		//SetRotation(glm::vec3(glfwGetTime(), glfwGetTime(), glfwGetTime()));
	}
	else
	{
		glm::vec3 basePos = glm::vec3(0.0, 0.0, -15.0);
		float x = sin(glfwGetTime()*2.0f) * 5.0f;
		float y = cos(glfwGetTime() * 2.0f) * 5.0f;
		float z = sin(glfwGetTime() * 2.0f) * 5.0f;
		glm::vec3 finalPos = basePos + glm::vec3(x, y, z);
		SetPosition(finalPos);
	}
	
	
}
