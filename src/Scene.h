#pragma once
#include "Singleton.h"

class Scene : public Singleton<Scene>
{

	public:
	
private:
	friend class Singleton<Scene>;
	Scene();
};