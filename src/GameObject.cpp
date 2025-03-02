#include "GameObject.h"

GameObject::GameObject(std::string name) : BaseObject(name) {}

void GameObject::Update()
{
	BaseObject::Update();
	if(!isLightCaster)
		SetRotation(glm::vec3(glfwGetTime(), 0.0, 0.0));
}
