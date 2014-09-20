#include "MainGameState.h"
#include <iostream>
#include "Player.h"
#include "SpriteManager.h"

MainGameState::MainGameState(SpriteManager *p_xSpriteManager) : State(p_xSpriteManager)
{
	m_xPlayer = new Player();

	m_xPlayer->SetGameObject(sf::Vector2f(100, 100), 64, 64, m_xSpriteManager->loadSprite("exit.png", 0, 0, 64, 64));

	m_vStateObjects.push_back(m_xPlayer);

	GameObject *obj;

	obj = new GameObject();

	obj->SetGameObject(sf::Vector2f(300, 300), 64, 64, m_xSpriteManager->loadSprite("exit.png", 0, 0, 64, 64));

	m_vStateObjects.push_back(obj);

	obj = new GameObject();

	obj->SetGameObject(sf::Vector2f(300, 600), 64, 64, m_xSpriteManager->loadSprite("exit.png", 0, 0, 64, 64));

	m_vStateObjects.push_back(obj);

	obj = new GameObject();

	obj->SetGameObject(sf::Vector2f(600, 600), 64, 64, m_xSpriteManager->loadSprite("exit.png", 0, 0, 64, 64));

	m_vStateObjects.push_back(obj);

	obj = new GameObject();

	obj->SetGameObject(sf::Vector2f(600, 300), 64, 64, m_xSpriteManager->loadSprite("exit.png", 0, 0, 64, 64));

	m_vStateObjects.push_back(obj);

	m_xInputHandler->MapFunctionToInput(InputHandler::FORWARD, std::bind(&Player::UpButtonPressed, m_xPlayer), true);
	m_xInputHandler->MapFunctionToInput(InputHandler::BACKWARDS, std::bind(&Player::DownButtonPressed, m_xPlayer), true);
	m_xInputHandler->MapFunctionToInput(InputHandler::RIGHT, std::bind(&Player::RightButtonPressed, m_xPlayer), true);
	m_xInputHandler->MapFunctionToInput(InputHandler::LEFT, std::bind(&Player::LeftButtonPressed, m_xPlayer), true);

	m_xInputHandler->MapInputToKey(sf::Keyboard::W, InputHandler::FORWARD, true);
	m_xInputHandler->MapInputToKey(sf::Keyboard::S, InputHandler::BACKWARDS, true);
	m_xInputHandler->MapInputToKey(sf::Keyboard::D, InputHandler::RIGHT, true);
	m_xInputHandler->MapInputToKey(sf::Keyboard::A, InputHandler::LEFT, true);

	m_xInputHandler->MapFunctionToInput(InputHandler::FORWARD, std::bind(&Player::UpButtonReleased, m_xPlayer), false);
	m_xInputHandler->MapFunctionToInput(InputHandler::BACKWARDS, std::bind(&Player::DownButtonReleased, m_xPlayer), false);
	m_xInputHandler->MapFunctionToInput(InputHandler::RIGHT, std::bind(&Player::RightButtonReleased, m_xPlayer), false);
	m_xInputHandler->MapFunctionToInput(InputHandler::LEFT, std::bind(&Player::LeftButtonReleased, m_xPlayer), false);

	m_xInputHandler->MapInputToKey(sf::Keyboard::W, InputHandler::FORWARD, false);
	m_xInputHandler->MapInputToKey(sf::Keyboard::S, InputHandler::BACKWARDS, false);
	m_xInputHandler->MapInputToKey(sf::Keyboard::D, InputHandler::RIGHT, false);
	m_xInputHandler->MapInputToKey(sf::Keyboard::A, InputHandler::LEFT, false);
}

void MainGameState::Enter()
{
	std::cout << "Entering Main Game State" << std::endl;
}

void MainGameState::Update(float p_fDeltaTime)
{
	for (auto object : m_vStateObjects)
	{
		if (object != nullptr)
		{
			//object->Update(p_fDeltaTime);
		}
	}

	m_xPlayer->Update(p_fDeltaTime);
}

void MainGameState::Exit()
{
	std::cout << "Exiting Main Game State" << std::endl;
}