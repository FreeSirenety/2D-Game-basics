#pragma once

#include <vector>
#include "SFML/Graphics.hpp"
#include "InputHandler.h"

class GameObject;
class SpriteManager;

class State
{

public:
	State(SpriteManager *p_xSpriteManager)
	{
		m_xInputHandler = new InputHandler();

		m_xSpriteManager = p_xSpriteManager;
	}

	virtual void Enter() = 0;

	virtual void Update(float p_fDeltaTime) = 0;

	virtual void Exit() = 0;

	std::vector<GameObject*> m_vStateObjects;

	virtual void HandleInput(sf::Keyboard::Key p_eKey, bool pressed)
	{
		m_xInputHandler->RunFunctionFromKey(p_eKey, pressed);
	}

protected:
	InputHandler *m_xInputHandler;

	SpriteManager *m_xSpriteManager;

};