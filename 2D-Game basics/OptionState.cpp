#include "OptionState.h"
#include <iostream>

OptionState::OptionState()
{

}

void OptionState::Enter()
{
	std::cout << "Entering Option State" << std::endl;
}

void OptionState::Update(float p_fDeltaTime)
{

}

void OptionState::Exit()
{
	std::cout << "Exiting Option State" << std::endl;
}