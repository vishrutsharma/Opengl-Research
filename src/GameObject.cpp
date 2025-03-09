#include "GameObject.h"
#include "Time.h"

GameObject::GameObject(std::string name) : BaseObject(name) {}

void GameObject::Update()
{
	BaseObject::Update();
	if (!isLightCaster)
	{
		SetRotation(glm::vec3(glfwGetTime(), glfwGetTime(), glfwGetTime()));
	}
	else
	{

	}
	
	
}
