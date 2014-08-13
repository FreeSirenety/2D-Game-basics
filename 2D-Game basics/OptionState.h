#pragma once

#include "State.h"

class OptionState : public State
{

public:
	OptionState();

	virtual void Enter();

	virtual void Update(float p_fDeltaTime);

	virtual void Exit();

private:


};