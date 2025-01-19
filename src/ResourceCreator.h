#pragma once

#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

namespace MeshResource
{
	Mesh* CreateMesh(const char* name);
}

namespace ShaderResource
{
	Shader* CreateShader(const char* vertexShaderPath,const char* fragmentShaderPath);
}

namespace TextureResource
{
	Texture2D* CreateTexture(int width,int height);
}