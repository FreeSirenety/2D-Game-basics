#include "DebugManager.h"
#include <iostream>

DebugManager::DebugManager()
{

}

void DebugManager::CreateDebugMessage(std::string p_xStringToWrite, MessageType p_xMessageType)
{

}

void DebugManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}

void DebugManager::Update(float p_fDeltaTime)
{
	std::cout << "The debug manager is updating and the entered number is: " << p_fDeltaTime << std::endl;
}