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
#include <string>
#include "BaseObject.h"

class BaseObject;

class MeshComponent
{
private:
	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;
	BaseObject* owner = nullptr;
	C_Mesh::Data m_data;

public:
	MeshComponent(const std::string& meshPath,BaseObject* baseObject);
	inline const C_Mesh::Data& GetData() { return m_data; }
	void Update();
	~MeshComponent();
};