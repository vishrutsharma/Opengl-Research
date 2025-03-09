#include "AppConfig.h"

namespace Config
{
	namespace WINDOW
	{
		const int SCREEN_WIDTH = 1920;
		const int SCREEN_HEIGHT = 1080;
		const char* WINDOW_TITLE = "Opengl Boilerplate";
	}

	namespace INPUT
	{
		const float MOUSE_SENSITIVITY = 0.1f;
	}

	namespace CAMERA
	{
		 const  float FOV = 45.0;
		 const  float NEAR_CLIP_PLANE = 0.1;
		 const  float FAR_CLIP_PLANE = 100.0;
	}

	namespace PATHS
	{
		 const char* MESH_PATH = "Assets/Mesh/Square.yaml";
		 const char* LIGHT_MESH_PATH = "Assets/Mesh/Cube.yaml";
		 const char* TEXTURE_PATH = "Assets/Textures/Texture0.png";
		 const char* VERTEX_SHADER_PATH = "Assets/Shaders/vertex.shader";
		 const char* FRAGMENT_SHADER_PATH = "Assets/Shaders/fragment.shader";
		 const char* LIGHT_VERTEX_SHADER_PATH = "Assets/Shaders/light_vertex.shader";
		 const char* LIGHT_FRAGMENT_SHADER_PATH = "Assets/Shaders/light_fragment.shader";
	}
}