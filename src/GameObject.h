#pragma once

#include "BaseObject.h"
#include "string"

class GameObject : public BaseObject
{
public:
	GameObject(std::string name);
	void Update() override;

private:

};