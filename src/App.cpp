#include "App.h"
#include "Mesh.h"
#include "Texture.h"
#include "AppConfig.h"
#include "Utils.h"


GLFWwindow* App::CreateAppWindow()
{
	m_window = glfwCreateWindow(Config::WINDOW::SCREEN_WIDTH, Config::WINDOW::SCREEN_HEIGHT, Config::WINDOW::WINDOW_TITLE, NULL, NULL);
	return m_window;
}

App::App()
{
	
}

void App::Init()
{
	const int CUBE_SIZE = 250;
	for (int i = 0; i < CUBE_SIZE; i++)
	{
		Mesh* m = new Mesh(Config::PATHS::MESH_PATH);
		Texture2D* t = new Texture2D();
		t->LoadTexture(Config::PATHS::TEXTURE_PATH);
		Shader* s = new Shader(Config::PATHS::VERTEX_SHADER_PATH, Config::PATHS::FRAGMENT_SHADER_PATH);
		m->SetTexture(t);
		m->SetShader(s);
		m_meshes.push_back(m);
		float rx = Utils::GET_RANDOM_NUMBER(-3.0, 3.0);
		float ry = Utils::GET_RANDOM_NUMBER(-3.0, 3.0);
		float rz = -Utils::GET_RANDOM_NUMBER(3.0, 80.0);
		float rscale = Utils::GET_RANDOM_NUMBER(0.2, 0.8);
		m->SetPosition(glm::vec3(rx,ry,rz));
		m->SetScale(rscale);	
	}
}

void App::ProcessInput()
{
	if (m_window == nullptr) return;

	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(m_window, true);
	}
}

void App::Render()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	if (m_meshes.size() == 0) return;

	for (Mesh* m : m_meshes)
	{
		m->Render();
	}
}

void App::Update()
{
	if (m_meshes.size() == 0) return;

	for (Mesh* m : m_meshes)
	{
		m->Update();
	}
}

App::~App()
{
	for (Mesh* m : m_meshes)
	{
		delete m;
	}

	delete m_window;
}