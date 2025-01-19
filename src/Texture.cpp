#include "Texture.h"
#include <cstring>
#include <iostream>
#include <filesystem>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture2D::Texture2D()
{
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
}

void Texture2D::LoadTexture(const char* texturePath)
{
	if (texturePath == nullptr || strlen(texturePath) == 0)
	{
		std::cout << "Texture Path is empty" << std::endl;
		return;
	}

	unsigned char* data = stbi_load(texturePath, &m_width, &m_height, &m_channels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		stbi_image_free(data);

	}
	else
	{
		std::cout << "Failed to load Texture:"<<stbi_failure_reason() << std::endl;
	}

	
}