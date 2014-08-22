#pragma once

#include "State.h"

class Player;
class SpriteManager;

class MainGameState : public State
{

public:
	MainGameState(SpriteManager *p_xSpriteManager);

	virtual void Enter();

	virtual void Update(float p_fDeltaTime);

	virtual void Exit();

private:
	Player *m_xPlayer;

};