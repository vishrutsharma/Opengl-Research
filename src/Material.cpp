#include "Material.h"
#include "Scene.h"

MaterialComponent::MaterialComponent(BaseObject* baseObject,glm::vec3 color, const char* vertexShaderPath, const char* fragmentShaderPath):owner(baseObject)
{
	m_color = color;
	m_shader = std::make_unique<Shader>(vertexShaderPath, fragmentShaderPath);
}

void MaterialComponent::Update()
{
	//glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, m_texture->ID);
	
	m_shader->Use();
	glm::vec3 lightColor;
	lightColor.x = abs(sin(glfwGetTime() * 2.0f));
	lightColor.y = abs(sin(glfwGetTime() * 0.7f));
	lightColor.z = abs(sin(glfwGetTime() * 1.3f));

	glm::vec3 diffuseColor = lightColor * glm::vec3(0.5f);
	glm::vec3 ambientColor = diffuseColor * glm::vec3(0.2f);
	glm::vec3 specularColor = glm::vec3(1.0, 1.0, 1.0);

	if (owner->IsLightCaster())
	{
		m_shader->SetVec3("lightColor", diffuseColor + ambientColor + specularColor);
	}
	else
	{
		m_shader->SetVec3("light.ambient", ambientColor);
		m_shader->SetVec3("light.diffuse", diffuseColor);
		m_shader->SetVec3("viewPos", Camera::GetInstance().GetPosition());
		m_shader->SetVec3("light.position", Scene::GetInstance().GetLight()->GetPosition());
		m_shader->SetVec3("material.ambient",glm::vec3(1.0f, 0.5f, 1.0f));
		m_shader->SetVec3("material.diffuse", m_color);
		m_shader->SetVec3("material.specular", glm::vec3(0.5f, 0.5f, 0.5f));
		m_shader->SetFloat("material.shininess", 32.0f);
	}

	

	
	
}