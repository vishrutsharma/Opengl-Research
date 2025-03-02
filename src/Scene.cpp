#include "Scene.h"
#include "Colors.h"

Scene::Scene()
{
	const glm::vec3& color = glm::vec3(0.1, 0.1, 0.1);
	m_ambientColor = color;
}
