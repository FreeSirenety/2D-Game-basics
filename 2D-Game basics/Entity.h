#pragma once

#include "GameObject.h"

class Entity : public GameObject
{

public:
	Entity();

	virtual void Update(float p_fDeltaTime);

	void SetVelocity(sf::Vector2f p_xNewVelocity);
	void AddVelocity(sf::Vector2f p_xVelocity);

	sf::Vector2f GetVelocity();

protected:
	sf::Vector2f m_xVelocity;
private:


};