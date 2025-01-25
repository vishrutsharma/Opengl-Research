#include "AppConfig.h"

namespace Config
{
	namespace WINDOW
	{
		const int SCREEN_WIDTH = 800;
		const int SCREEN_HEIGHT = 800;
		const char* WINDOW_TITLE = "Opengl Boilerplate";
	}

	namespace CAMERA
	{
		 const  float FOV = 45.0;
		 const  float NEAR_CLIP_PLANE = 0.1;
		 const  float FAR_CLIP_PLANE = 100.0;
	}

	namespace PATHS
	{
		 const char* TEXTURE_PATH = "media/Texture0.png";
		 const char* VERTEX_SHADER_PATH = "src/Shaders/vertex.SHADER";
		 const char* FRAGMENT_SHADER_PATH = "src/Shaders/fragment.SHADER";
	}
}