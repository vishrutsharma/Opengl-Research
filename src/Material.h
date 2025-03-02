#pragma once

#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <glm.hpp>
#include "Shader.h"
#include "Texture.h"
#include <memory>
#include <string>

class MaterialComponent
{

public:
	MaterialComponent(glm::vec3 color,const std::string& vertexShaderPath,const std::string& fragmentShaderPath);
	//inline void SetColor(glm::vec3 color) const { m_color = color; }
	inline const glm::vec3& GetColor() const { return m_color; }
	inline unsigned int GetShaderId() { return m_shader->ID; }
	void Update();

private:
	glm::vec3 m_color;
	std::unique_ptr<Shader> m_shader;
	//std::unique_ptr<Texture2D> m_texture;
};