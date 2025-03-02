#include "App.h"
#include "Mesh.h"
#include "Texture.h"
#include "AppConfig.h"
#include "Utils.h"
#include "Camera.h"
#include "Time.h"
#include "Colors.h"
#include "Scene.h"


using namespace InputSystem;

GLFWwindow* App::CreateAppWindow()
{
	m_window = glfwCreateWindow(Config::WINDOW::SCREEN_WIDTH, Config::WINDOW::SCREEN_HEIGHT, Config::WINDOW::WINDOW_TITLE, NULL, NULL);
	return m_window;
}

App::App() : m_framesSampleCount(0),
			m_frames(0),
			m_elapsedTime(0),
			m_lastMouseXPos(0),
			m_lastMouseYPos(0),
			m_mousePitch(0),
			m_mouseYaw(-90.0f){}

void App::Init()
{
	m_elapsedTime = Time::GetInstance().GetTimeSinceStart();
	m_inputManager = new InputManager(m_window);
	m_keyBindings = new KeyBindings();
	glfwSetWindowUserPointer(m_window,m_inputManager);
	m_keyBindings->BindKey(GLFW_KEY_W,Action::MOVE_FORWARD);
	m_keyBindings->BindKey(GLFW_KEY_A, Action::MOVE_LEFT);
	m_keyBindings->BindKey(GLFW_KEY_D, Action::MOVE_RIGHT);
	m_keyBindings->BindKey(GLFW_KEY_S, Action::MOVE_BACKWARD);
	
	const int OBJECT_SIZE = 250;
	for (int i = 0; i < OBJECT_SIZE; i++)
	{
		GameObject* gObject = new GameObject("GameObject_"+std::to_string(i));
		gObject->AddMeshComponent(Config::PATHS::MESH_PATH);
		gObject->AddMaterialComponent(GetVec3Color(Color::White),Config::PATHS::VERTEX_SHADER_PATH,Config::PATHS::FRAGMENT_SHADER_PATH);

		float rx = Utils::GET_RANDOM_NUMBER(-4.0, 4.0);
		float ry = Utils::GET_RANDOM_NUMBER(-4.0, 4.0);
		float rz = -Utils::GET_RANDOM_NUMBER(4.0, 180.0);
		glm::vec3 pos = glm::vec3(rx, ry, rz);
		float rScale = Utils::GET_RANDOM_NUMBER(0.2, 0.8);
		
		gObject->SetPosition(pos); 
		gObject->SetScale(glm::vec3(rScale, rScale, rScale));
		m_gameObjects.push_back(gObject);
	}

	//Init Light
	m_light = new GameObject("Light");
	m_light->AddMeshComponent(Config::PATHS::LIGHT_MESH_PATH);
	m_light->AddMaterialComponent(GetVec3Color(Color::Yellow), Config::PATHS::LIGHT_VERTEX_SHADER_PATH, Config::PATHS::LIGHT_FRAGMENT_SHADER_PATH);
	
	
	m_light->SetPosition(glm::vec3(15.0, 5.0, -25.0));
	
	m_light->SetScale(glm::vec3(5.5, 5.5, 5.5));
	m_light->SetAsLightCaster(true);
	Scene::GetInstance().SetLight(m_light);
}

void App::ProcessInput()
{
	if (m_window == nullptr) return;

	// ------------------------- KEYBOARD --------------------------------------
	if (m_keyBindings->IsActionTriggered(Action::MOVE_FORWARD, m_inputManager))
	{
		Camera::GetInstance().MoveCamera(Action::MOVE_FORWARD);
	}
	if (m_keyBindings->IsActionTriggered(Action::MOVE_BACKWARD, m_inputManager))
	{
		Camera::GetInstance().MoveCamera(Action::MOVE_BACKWARD);
	}
	if (m_keyBindings->IsActionTriggered(Action::MOVE_LEFT, m_inputManager))
	{
		Camera::GetInstance().MoveCamera(Action::MOVE_LEFT);
	}
	if (m_keyBindings->IsActionTriggered(Action::MOVE_RIGHT, m_inputManager))
	{
		Camera::GetInstance().MoveCamera(Action::MOVE_RIGHT);
	}
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(m_window, true);
	}



	// -------------------------- MOUSE -------------------------------------------


	int mouseXPos = 0;
	int mouseYPos = 0;
	m_inputManager->GetMousePosition(mouseXPos, mouseYPos);

	int diffX = mouseXPos - m_lastMouseXPos;
	int diffY = m_lastMouseYPos - mouseYPos ;

	m_lastMouseXPos = mouseXPos;
	m_lastMouseYPos = mouseYPos;
	diffX *= (int)Config::INPUT::MOUSE_SENSITIVITY;
	diffY *= (int)Config::INPUT::MOUSE_SENSITIVITY;

	m_mousePitch += diffY;
	m_mouseYaw += diffX;

	const float pitchClamp = 89.0f;
	m_mousePitch = std::clamp(m_mousePitch, -89.0f, 89.0f);
	Camera::GetInstance().SetForward(Utils::GetDirectionFromAxis(m_mouseYaw,m_mousePitch));
}

void App::Render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

}

void App::CalculateFPS()
{
	float deltaTime = Time::GetInstance().GetDeltaTime();
	m_elapsedTime += deltaTime;
	m_framesSampleCount++;

	if (m_elapsedTime >= 1.0f)
	{
		m_frames = m_framesSampleCount;
		m_framesSampleCount = 0;
		m_elapsedTime = 0.0f;
	}	
}

void App::Update()
{
	CalculateFPS();

	m_inputManager->Update();
	Camera::GetInstance().Update();
	Time::GetInstance().Update();

	if (m_light)
		m_light->Update();

	if (m_gameObjects.size() == 0) return;
	for (GameObject* gOb : m_gameObjects)
	{
		gOb->Update();
	}
}

App::~App()
{
	for (GameObject* gOb : m_gameObjects)
	{
		delete gOb;
	}

	delete m_light;
	delete m_window;
}