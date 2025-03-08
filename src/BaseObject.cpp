#include "BaseObject.h"

void BaseObject::Update()
{
	if (m_materialComponent)
		m_materialComponent->Update();

	if (m_meshComponent)
		m_meshComponent->Update();
}

BaseObject::~BaseObject()
{
	
}