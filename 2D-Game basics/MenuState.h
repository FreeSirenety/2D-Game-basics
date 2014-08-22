#pragma once

#include "State.h"

class SpriteManager;

class MenuState : public State
{

public:
	MenuState(SpriteManager *p_xSpriteManager);

	virtual void Enter();

	virtual void Update(float p_fDeltaTime);

	virtual void Exit();

private:


};