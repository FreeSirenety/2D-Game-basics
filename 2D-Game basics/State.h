#pragma once

#include <vector>

class Object;

class State
{

public:

	virtual void Enter() = 0;

	virtual void Update(float p_fDeltaTime) = 0;

	virtual void Exit() = 0;

	std::vector<Object*> m_vStateObjects;

};