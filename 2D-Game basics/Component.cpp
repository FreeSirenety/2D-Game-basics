#include "Component.h"

Component::Component()
{

}

void Component::Update(float p_fDeltaTime)
{

}

void Component::SetParent(GameObject *p_xParentObject)
{
	m_xParentObject = p_xParentObject;
}

GameObject *Component::GetParent()
{
	return m_xParentObject;
}