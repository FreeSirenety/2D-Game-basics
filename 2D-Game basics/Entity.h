#pragma once

#include "GameObject.h"
#include "SFML/Graphics.hpp"

class Entity : public GameObject
{

public:
	Entity();

	virtual void Update(float p_fDeltaTime);

	virtual void Move(float p_fDeltaTime);

	void SetVelocity(sf::Vector2f p_xNewVelocity);
	void AddVelocity(sf::Vector2f p_xVelocity);

	sf::Vector2f GetVelocity();

	void SetSpeed(float p_fNewSpeed);
	float GetSpeed();

protected:
	sf::Vector2f m_xVelocity;

	float m_fSpeed;
private:

};