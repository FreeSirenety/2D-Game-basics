#pragma once

#include <map>

class State;

class StateManager
{

public:
	enum States
	{
		MENUSTATE,
		OPTIONSTATE,
		STARTSTATE
	};

public:
	StateManager();

	void Update(float DeltaTime);

	void UpdateCurrentState(float p_fDeltaTime);

	void DrawCurrentState();

	void QueueStateForChange(States p_eNewState);

	void HandleQueuedChanges();

	States GetCurrentState();

private:
	std::map<States, State*> m_mStates;

	States m_eCurrentState;

	States m_eQueuedState;

	bool m_bIsStateChangeQueued;
};