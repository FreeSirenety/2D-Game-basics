#include "Entity.h"

Entity::Entity()
{

}

void Entity::Update(float p_fDeltaTime)
{

}

void Entity::SetVelocity(sf::Vector2f p_xNewVelocity)
{
	m_xVelocity = p_xNewVelocity;
}

void Entity::AddVelocity(sf::Vector2f p_xVelocity)
{
	m_xVelocity += p_xVelocity;
}

sf::Vector2f Entity::GetVelocity()
{
	return m_xVelocity;
}