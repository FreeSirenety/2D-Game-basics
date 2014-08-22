#include "MenuState.h"
#include <iostream>

MenuState::MenuState(SpriteManager *p_xSpriteManager) : State(p_xSpriteManager)
{

}

void MenuState::Enter()
{
	std::cout << "Entering Menu State" << std::endl;
}

void MenuState::Update(float p_fDeltaTime)
{

}

void MenuState::Exit()
{
	std::cout << "Exiting Menu State" << std::endl;
}