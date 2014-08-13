#include "StateManager.h"
#include "State.h"

#include "MenuState.h"
#include "OptionState.h"
#include "StartState.h"

StateManager::StateManager()
{
	m_bIsStateChangeQueued = false;

	MenuState *menuState = new MenuState();
	OptionState *optionState = new OptionState();
	StartState *startState = new StartState();

	std::pair<States, State*> menuPair(MENUSTATE, menuState);
	std::pair<States, State*> optionPair(OPTIONSTATE, optionState);
	std::pair<States, State*> startPair(STARTSTATE, startState);

	m_mStates.insert(menuPair);
	m_mStates.insert(optionPair);
	m_mStates.insert(startPair);

	m_eCurrentState = STARTSTATE;
}

void StateManager::Update(float DeltaTime)
{
	UpdateCurrentState(DeltaTime);

	DrawCurrentState();

	if (m_bIsStateChangeQueued)
	{
		HandleQueuedChanges();
	}
}

void StateManager::UpdateCurrentState(float p_fDeltaTime)
{
	if (m_mStates.find(m_eCurrentState) != m_mStates.end())
	{
		m_mStates.find(m_eCurrentState)->second->Update(p_fDeltaTime);
	}
}

void StateManager::DrawCurrentState()
{

}

void StateManager::QueueStateForChange(States p_eNewState)
{
	m_eQueuedState = p_eNewState;

	m_bIsStateChangeQueued = true;
}

void StateManager::HandleQueuedChanges()
{
	if (m_mStates.find(m_eCurrentState) != m_mStates.end())
	{
		m_mStates.find(m_eCurrentState)->second->Exit();
	}

	m_eCurrentState = m_eQueuedState;

	m_bIsStateChangeQueued = false;
}

StateManager::States StateManager::GetCurrentState()
{
	return m_eCurrentState;
}