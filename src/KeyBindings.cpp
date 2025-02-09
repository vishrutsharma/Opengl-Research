#include "KeyBindings.h"

using namespace InputSystem;


KeyBindings::KeyBindings() {}


void KeyBindings::BindKey(int key, Action action)
{
	m_mappings.insert(std::make_pair(action, key));
}

const int KeyBindings::GetBoundKey(Action action)
{
	auto it = m_mappings.find(action);
	return it != m_mappings.end() ? it->second : -1;
}

bool KeyBindings::IsActionTriggered(Action action,InputManager* inputManager)
{
	int key = GetBoundKey(action);
	return key != -1 && inputManager->IsKeyPressed(key);
}