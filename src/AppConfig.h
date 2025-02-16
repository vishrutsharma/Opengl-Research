#pragma once

namespace Config
{
	namespace WINDOW
	{
		extern const int SCREEN_WIDTH;
		extern const int SCREEN_HEIGHT;
		extern const char* WINDOW_TITLE;
	}

	namespace INPUT
	{
		extern const int SCROLL_SPEED;
	}

	namespace CAMERA
	{
		extern const  float FOV ;
		extern const  float NEAR_CLIP_PLANE;
		extern const  float FAR_CLIP_PLANE;
	}

	namespace PATHS
	{
		extern const char* MESH_PATH;
		extern const char* TEXTURE_PATH;
		extern const char* VERTEX_SHADER_PATH;
		extern const char* FRAGMENT_SHADER_PATH;
	}
	
}