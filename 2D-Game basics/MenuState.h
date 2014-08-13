#pragma once

#include "State.h"

class MenuState : public State
{

public:
	MenuState();

	virtual void Enter();

	virtual void Update(float p_fDeltaTime);

	virtual void Exit();

private:


};