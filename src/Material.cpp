#include "Material.h"
#include "Scene.h"

MaterialComponent::MaterialComponent(glm::vec3 color, const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
{
	m_color = color;
	m_shader = std::make_unique<Shader>(vertexShaderPath.c_str(), fragmentShaderPath.c_str());
}

void MaterialComponent::Update()
{
	//glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, m_texture->ID);
	glUseProgram(m_shader->ID);
	m_shader->SetVec3("objectColor", m_color);
	/*m_shader->SetVec3("lightColor", Scene::GetInstance().GetLight()->GetMaterial()->GetColor());
	m_shader->SetVec3("ambientColor", Scene::GetInstance().GetAmbientColor());
	m_shader->SetVec3("lightPos", Scene::GetInstance().GetLight()->GetPosition());
	*/
	m_shader->Use();

	//glUniform1i(glGetUniformLocation(m_shader->ID, "ourTexture"), 0);
}