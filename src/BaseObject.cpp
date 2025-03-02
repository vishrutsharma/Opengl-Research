#include "BaseObject.h"

void BaseObject::Update()
{
	if (!m_meshComponent)
		return;

	unsigned int shaderId = -1;
	if (m_materialComponent)
	{
		shaderId = m_materialComponent->GetShaderId();
	}
	m_meshComponent->Update(m_position,m_rotation,m_scale,shaderId);
	m_materialComponent->Update();
}

BaseObject::~BaseObject()
{
	
}