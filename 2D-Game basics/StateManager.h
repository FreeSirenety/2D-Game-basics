#pragma once

#include <map>
#include "SFML/Graphics.hpp"

class State;
class DrawManager;
class SpriteManager;

class StateManager
{

public:
	enum States
	{
		MENUSTATE,
		OPTIONSTATE,
		STARTSTATE,
		MAINGAMESTATE
	};

public:
	StateManager(DrawManager *p_xDrawManager, SpriteManager *p_xSpriteManager);

	void Update(float DeltaTime);

	void UpdateCurrentState(float p_fDeltaTime);

	void DrawCurrentState();

	void QueueStateForChange(States p_eNewState);

	void HandleQueuedChanges();

	States GetCurrentState();

	void HandleEvent(sf::Keyboard::Key p_eKey, bool pressed);

private:
	std::map<States, State*> m_mStates;

	States m_eCurrentState;

	States m_eQueuedState;

	bool m_bIsStateChangeQueued;

	DrawManager *m_xDrawManager;

	SpriteManager *m_xSpriteManager;
};