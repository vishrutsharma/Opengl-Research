#include "MeshLoader.h"
#include <string>

C_Mesh::Data MeshLoader::LoadMesh(const char* path)
{
	C_Mesh::Data mData;
	YAML::Node root = YAML::LoadFile(path);
	if (root.IsNull())
	{
		std::cout << "Failed to load Mesh Data from YAML" << std::endl;
		return mData;
	}

	std::string meshName = root["name"].as<std::string>();
	std::vector<C_Graphics::Vertex> vertices;

	for (const auto& v : root["vertices"])
	{
		C_Graphics::Vertex vertex;
		vertex.position = glm::vec3(v["position"][0].as<float>(), v["position"][1].as<float>(), v["position"][2].as<float>());
		vertex.vertexColors = glm::vec3(v["color"][0].as<float>(), v["color"][1].as<float>(), v["color"][2].as<float>());
		vertex.uvCoodinates = glm::vec2(v["uv"][0].as<float>(), v["uv"][1].as<float>());
		vertex.vertexNormals = glm::vec3(v["normal"][0].as<float>(), v["normal"][1].as<float>(), v["normal"][2].as<float>());
		vertices.push_back(vertex);
	}

	std::vector<unsigned int> ind;
	for (const auto indices : root["indices"])
	{
		ind.push_back(indices.as<unsigned int>());
	}

	
	mData.name = meshName;
	mData.indices = ind;
	mData.vertices = vertices;

	return mData;
}