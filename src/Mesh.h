#pragma once

#include <vector>
#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <glm.hpp>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "Components.h"
#include "Shader.h"
#include "Texture.h"

class Mesh
{

private:
	void SET_TRANSFORMATION_MATRIX();
	const char* name;
	std::vector<Components::Vertex*> m_vertices;
	Shader* m_shader;
	Texture2D* m_texture;
	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;
	float m_scale;
	float m_rotation;
	glm::vec3 m_position;

public:
	Mesh(const char* _name);
	inline void SetPosition(const glm::vec3& pos) { m_position = pos; }
	inline void SetRotation(const float degree) { m_rotation = degree; }
	inline void SetScale(const float scale) { m_scale = scale; }
	inline void SetShader(Shader* shader) { m_shader = shader; }
	inline void SetTexture(Texture2D* texture) { m_texture = texture; }

	void AddVertex(const glm::vec3 _vector, const glm::vec3 _color, const glm::vec2 _uvCoodinates);
	void Update();
	void Render();
	~Mesh();

};