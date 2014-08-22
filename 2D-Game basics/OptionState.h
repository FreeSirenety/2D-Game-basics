#pragma once

#include "State.h"

class SpriteManager;

class OptionState : public State
{

public:
	OptionState(SpriteManager *p_xSpriteManager);

	virtual void Enter();

	virtual void Update(float p_fDeltaTime);

	virtual void Exit();

private:


};