#pragma once
#include "Actions.h"
#include "InputManager.h"
#include <unordered_map>

namespace InputSystem
{
	class KeyBindings
	{
	public:
		KeyBindings();
		void BindKey(int, Action);
		int GetBoundKey(Action);
		bool IsActionTriggered(Action,InputManager*);

	private:
		std::unordered_map<Action,int> m_mappings;
	};
}