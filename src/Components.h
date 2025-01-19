#pragma once
#include <glm.hpp>

namespace Components
{
	struct Vertex
	{
		glm::vec3 position;
		glm::vec3 vertexColors;
		glm::vec2 uvCoodinates;
	};
}