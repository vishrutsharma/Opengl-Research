#pragma once
#include <glad\glad.h>

class Texture2D
{
public:
	Texture2D();
	void LoadTexture(const char* texturePath);
	unsigned int ID;

private :
	int m_width;
	int m_height;
	int m_channels;
};