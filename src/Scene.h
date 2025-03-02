#pragma once
#include "Singleton.h"
#include <glm.hpp>
#include "GameObject.h"

class Scene : public Singleton<Scene>
{

public:
		inline GameObject* GetLight() { return m_light; }
		inline void SetLight(GameObject* light) { m_light = light; }
		const inline glm::vec3& GetAmbientColor() { return m_ambientColor; }
	
private:
	friend class Singleton<Scene>;
	Scene();

	GameObject* m_light = nullptr;
	glm::vec3 m_ambientColor;
	 
};