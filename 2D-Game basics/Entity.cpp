#include "Entity.h"
#include <math.h>

Entity::Entity() : GameObject()
{

}

void Entity::Update(float p_fDeltaTime)
{
	GameObject::Update(p_fDeltaTime);
}

void Entity::Move(float p_fDeltaTime)
{
	if (m_xVelocity.x < 0.000001 && m_xVelocity.x > -0.000001)
	{
		if (m_xVelocity.y < 0.000001 && m_xVelocity.y > -0.000001)
		{
			return;
		}
	}

	float fVelocityLength = sqrtf(m_xVelocity.x * m_xVelocity.x + m_xVelocity.y * m_xVelocity.y);

	sf::Vector2f xNormalizedVelocity = m_xVelocity / fVelocityLength;

	SetPos(GetPos() + sf::Vector2f(xNormalizedVelocity * m_fSpeed * p_fDeltaTime));

	m_xSprite->setPosition(GetPos());
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

void Entity::SetSpeed(float p_fNewSpeed)
{
	m_fSpeed = p_fNewSpeed;
}

float Entity::GetSpeed()
{
	return m_fSpeed;
}