#include "MainGameState.h"
#include <iostream>
#include "Player.h"
#include "SpriteManager.h"

MainGameState::MainGameState(SpriteManager *p_xSpriteManager) : State(p_xSpriteManager)
{
	m_xPlayer = new Player();

	m_xPlayer->SetSprite(m_xSpriteManager->loadSprite("exit.png", 0, 0, 64, 64));

	m_vStateObjects.push_back(m_xPlayer);

	m_xInputHandler->MapFunctionToInput(InputHandler::FORWARD, std::bind(&Player::UpButtonPressed, m_xPlayer));
	m_xInputHandler->MapFunctionToInput(InputHandler::BACKWARDS, std::bind(&Player::DownButtonPressed, m_xPlayer));
	m_xInputHandler->MapFunctionToInput(InputHandler::RIGHT, std::bind(&Player::RightButtonPressed, m_xPlayer));
	m_xInputHandler->MapFunctionToInput(InputHandler::LEFT, std::bind(&Player::LeftButtonPressed, m_xPlayer));

	m_xInputHandler->MapInputToKey(sf::Keyboard::W, InputHandler::FORWARD);
	m_xInputHandler->MapInputToKey(sf::Keyboard::S, InputHandler::BACKWARDS);
	m_xInputHandler->MapInputToKey(sf::Keyboard::D, InputHandler::RIGHT);
	m_xInputHandler->MapInputToKey(sf::Keyboard::A, InputHandler::LEFT);
}

void MainGameState::Enter()
{
	std::cout << "Entering Main Game State" << std::endl;
}

void MainGameState::Update(float p_fDeltaTime)
{

}

void MainGameState::Exit()
{
	std::cout << "Exiting Main Game State" << std::endl;
}