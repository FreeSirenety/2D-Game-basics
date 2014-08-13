#pragma once

#include "State.h"

class StartState : public State
{
public:
	StartState();

	virtual void Enter();

	virtual void Update(float p_fDeltaTime);

	virtual void Exit();

private:

};