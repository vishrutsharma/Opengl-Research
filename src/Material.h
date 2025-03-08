#pragma once

#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <glm.hpp>
#include "Shader.h"
#include "Texture.h"
#include <memory>
#include <string>
#include "BaseObject.h"

class BaseObject;
class MaterialComponent
{

public:
	MaterialComponent(BaseObject* bOb,glm::vec3 color,const char* vertexShaderPath,const char* fragmentShaderPath);
	//inline void SetColor(glm::vec3 color) const { m_color = color; }
	inline const glm::vec3& GetColor() const { return m_color; }
	inline unsigned int GetShaderId() const { return m_shader->ID; }
	void Update();

private:
	BaseObject* owner = nullptr;
	glm::vec3 m_color;
	std::unique_ptr<Shader> m_shader;
	//std::unique_ptr<Texture2D> m_texture;
};