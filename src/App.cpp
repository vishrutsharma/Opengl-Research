#include "App.h"
#include "Mesh.h"
#include "Texture.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const char* WINDOW_TITLE = "Opengl Tutorials";
const char* TEXTURE_PATH = "media/Texture0.png";
const char* VERTEX_SHADER_PATH = "src/Shaders/vertex.SHADER";
const char* FRAGMENT_SHADER_PATH = "src/Shaders/fragment.SHADER";

GLFWwindow* App::CreateAppWindow()
{
	m_window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE, NULL, NULL);
	return m_window;
}

App::App()
{
	
}

void App::Init()
{
	Mesh* m = new Mesh("My Mesh");
	Shader* s = new Shader(VERTEX_SHADER_PATH,FRAGMENT_SHADER_PATH);
	Texture2D* t = new Texture2D();
	t->LoadTexture(TEXTURE_PATH);
	m->SetTexture(t);
	m->SetShader(s);
	m_meshes.push_back(m);
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