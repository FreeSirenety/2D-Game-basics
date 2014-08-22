#pragma once

#include "State.h"

class SpriteManager;

class StartState : public State
{
public:
	StartState(SpriteManager *p_xSpriteManager);

	virtual void Enter();

	virtual void Update(float p_fDeltaTime);

	virtual void Exit();

private:

};