#pragma once

#include <vector>

class GameObject;

class State
{

public:

	virtual void Enter() = 0;

	virtual void Update(float p_fDeltaTime) = 0;

	virtual void Exit() = 0;

	std::vector<GameObject*> m_vStateObjects;

};