#include "StartState.h"
#include <iostream>

StartState::StartState(SpriteManager *p_xSpriteManager) : State(p_xSpriteManager)
{

}

void StartState::Enter()
{
	std::cout << "Entering Start State" << std::endl;
}

void StartState::Update(float p_fDeltaTime)
{

}

void StartState::Exit()
{
	std::cout << "Exiting Start State" << std::endl;
}