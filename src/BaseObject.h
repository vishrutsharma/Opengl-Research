#pragma once

#include <string>
#include "Mesh.h"
#include "Material.h"
#include <memory>
#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <string>

class BaseObject
{
public:
	BaseObject(const std::string& name) : m_name(name) {}
	inline const std::string& GetName() { return m_name; }
	inline void SetPosition(glm::vec3 pos) { m_position = pos; }
	inline const glm::vec3& GetPosition() { return m_position; }
	
	inline void SetRotation(glm::vec3 rotation) { m_rotation = rotation; }
	inline void SetScale(glm::vec3 scale) { m_scale = scale; }

	inline void AddMeshComponent(const std::string& meshPath) { 
		m_meshComponent = std::make_unique<MeshComponent>(meshPath);}

	inline void AddMaterialComponent(glm::vec3 color,const std::string& vertexShaderPath,const std::string& fragmentShaderPath) { 
		m_materialComponent = std::make_unique<MaterialComponent>(color,vertexShaderPath,fragmentShaderPath); }

	inline const std::unique_ptr<MeshComponent>& GetMesh() { return m_meshComponent; }
	inline const std::unique_ptr<MaterialComponent>& GetMaterial() { return m_materialComponent; }
	inline void SetAsLightCaster(bool active) { isLightCaster = active; }
	inline bool IsLightCaster() { return isLightCaster; }

	virtual void Update();
	virtual ~BaseObject();

private:
	glm::vec3 m_rotation;
	glm::vec3 m_position;
	glm::vec3 m_scale;
	
protected:
	bool isLightCaster = false;
	std::string m_name;
	std::unique_ptr<MeshComponent> m_meshComponent;
	std::unique_ptr<MaterialComponent> m_materialComponent;
};