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

	if (owner->IsLightCaster())
	{
		m_shader->SetVec3("lightColor", lightColor);
	}
	else
	{
		
		m_shader->SetVec3("lightMaterial.color", lightColor);
		m_shader->SetVec3("viewPos", Camera::GetInstance().GetPosition());
		m_shader->SetVec3("lightMaterial.position", Scene::GetInstance().GetLight()->GetPosition());
		m_shader->SetVec3("material.ambient", glm::vec3(0.2f, 0.2f, 0.2f));
		m_shader->SetVec3("material.diffuse", m_color);
		m_shader->SetVec3("material.specular", glm::vec3(0.5f, 0.5f, 0.5f));
		m_shader->SetFloat("material.shininess", 32.0f);
	}

}