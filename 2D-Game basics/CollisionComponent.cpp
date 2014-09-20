#include "CollisionComponent.h"

CollisionComponent::CollisionComponent(GameObject *p_xParentObject, bool p_bIsActive)
{
	m_xParentObject = p_xParentObject;
	m_bIsActive = p_bIsActive;
}

void CollisionComponent::SetActive(bool p_bIsActive)
{
	m_bIsActive = p_bIsActive;
}

bool CollisionComponent::GetIsActive()
{
	return m_bIsActive;
}

void CollisionComponent::Update(float p_fDeltaTime)
{

}