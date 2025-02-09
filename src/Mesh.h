#pragma once

#include <vector>
#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "Components.h"
#include "Shader.h"
#include "Texture.h"
#include "MeshLoader.h"
#include "Camera.h"

class Mesh
{

private:
	void SET_TRANSFORMATION_MATRIX();
	Shader* m_shader;
	Texture2D* m_texture;
	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;
	float m_scale;
	float m_rotation;
	glm::vec3 m_position;
	C_Mesh::Data m_data;

public:
	Mesh(const char* path);
	inline void SetPosition(const glm::vec3& pos) { m_position = pos; }
	inline void SetRotation(const float degree) { m_rotation = degree; }
	inline void SetScale(const float scale) { m_scale = scale; }
	inline void SetShader(Shader* shader) { m_shader = shader; }
	inline void SetTexture(Texture2D* texture) { m_texture = texture; }
	inline const C_Mesh::Data& GetData() { return m_data; }
	void Update();
	void Render();
	~Mesh();

};