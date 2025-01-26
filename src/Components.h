#pragma once
#include <glm.hpp>
#include <string>

	namespace C_Graphics
	{
		struct Vertex
		{
			glm::vec3 position;
			glm::vec3 vertexColors;
			glm::vec2 uvCoodinates;
		};
	}
	
	namespace C_Mesh
	{
		struct Data
		{
			std::string name;
			std::vector<C_Graphics::Vertex> vertices;
			std::vector<unsigned int> indices;
			bool IsValid() const {
				return !name.empty() && !vertices.empty() && !indices.empty();
			}
		};
	}