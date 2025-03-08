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
	if (owner->IsLightCaster())
	{
		m_shader->SetVec3("lightColor", m_color);
	}
	else
	{
		m_shader->SetVec3("objectColor", m_color);
		m_shader->SetVec3("lightColor", Scene::GetInstance().GetLight()->GetMaterial()->GetColor());
		m_shader->SetVec3("ambientColor", Scene::GetInstance().GetAmbientColor());
		m_shader->SetVec3("lightPos", Scene::GetInstance().GetLight()->GetPosition());
	}
	
	//glUniform1i(glGetUniformLocation(m_shader->ID, "ourTexture"), 0);
}