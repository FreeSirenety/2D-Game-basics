#include "StateManager.h"
#include "State.h"

#include "MenuState.h"
#include "OptionState.h"
#include "StartState.h"
#include "MainGameState.h"

#include "DrawManager.h"
#include "SpriteManager.h"

StateManager::StateManager(DrawManager *p_xDrawManager, SpriteManager *p_xSpriteManager)
{
	m_bIsStateChangeQueued = false;

	MenuState *menuState = new MenuState(p_xSpriteManager);
	OptionState *optionState = new OptionState(p_xSpriteManager);
	StartState *startState = new StartState(p_xSpriteManager);
	MainGameState *mainGameState = new MainGameState(p_xSpriteManager);

	std::pair<States, State*> menuPair(MENUSTATE, menuState);
	std::pair<States, State*> optionPair(OPTIONSTATE, optionState);
	std::pair<States, State*> startPair(STARTSTATE, startState);
	std::pair<States, State*> mainGamePair(MAINGAMESTATE, mainGameState);

	m_mStates.insert(menuPair);
	m_mStates.insert(optionPair);
	m_mStates.insert(startPair);
	m_mStates.insert(mainGamePair);

	m_eCurrentState = MAINGAMESTATE;

	m_xDrawManager = p_xDrawManager;
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
	if (m_mStates.find(m_eCurrentState) != m_mStates.end())
	{
		m_xDrawManager->DrawObjectVector(m_mStates.find(m_eCurrentState)->second->m_vStateObjects);
	}
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

	if (m_mStates.find(m_eCurrentState) != m_mStates.end())
	{
		m_mStates.find(m_eCurrentState)->second->Enter();
	}

	m_bIsStateChangeQueued = false;
}

StateManager::States StateManager::GetCurrentState()
{
	return m_eCurrentState;
}

void StateManager::HandleEvent(sf::Keyboard::Key p_eKey, bool pressed)
{
	if (m_mStates.find(m_eCurrentState) != m_mStates.end())
	{
		m_mStates.find(m_eCurrentState)->second->HandleInput(p_eKey, pressed);
	}
}