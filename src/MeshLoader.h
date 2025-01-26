#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Components.h"
#include <yaml-cpp\yaml.h>

class MeshLoader
{
	public:
		static C_Mesh::Data LoadMesh(const char* path);
};