#include "Engine.h"
#include "InputHandler.h"
#include <iostream>
#include "StateManager.h"
#include "DrawManager.h"
#include "SpriteManager.h"

Engine::Engine()
{
	m_xMainWindow = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");

	m_xDrawManager = new DrawManager(m_xMainWindow);

	m_xSpriteManager = new SpriteManager("");

	m_xStateManager = new StateManager(m_xDrawManager, m_xSpriteManager);
}

void Engine::Run()
{
	InputHandler *inputHandler = new InputHandler();

	inputHandler->MapFunctionToInput(InputHandler::FORWARD, std::bind(&Engine::TestInput, this));
	inputHandler->MapFunctionToInput(InputHandler::BACKWARDS, std::bind(&Engine::SetStartState, this));
	inputHandler->MapFunctionToInput(InputHandler::LEFT, std::bind(&Engine::SetMenuState, this));
	inputHandler->MapFunctionToInput(InputHandler::RIGHT, std::bind(&Engine::SetOptionState, this));

	inputHandler->MapInputToKey(sf::Keyboard::W, InputHandler::FORWARD);
	inputHandler->MapInputToKey(sf::Keyboard::A, InputHandler::BACKWARDS);
	inputHandler->MapInputToKey(sf::Keyboard::S, InputHandler::LEFT);
	inputHandler->MapInputToKey(sf::Keyboard::D, InputHandler::RIGHT);

	while (m_xMainWindow->isOpen())
	{
		m_xMainWindow->clear();
		sf::Event event;
		while (m_xMainWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_xMainWindow->close();

			if (event.type == sf::Event::KeyPressed)
				m_xStateManager->HandleEvent(event.key.code);

			/*if (event.type == sf::Event::MouseButtonPressed)
				inputHandler->RebindOnNextKeyEvent(InputHandler::FORWARD);*/

		}

		m_xStateManager->Update(0);

		
		m_xMainWindow->display();
	}
}

void Engine::Cleanup()
{

}

void Engine::TestInput()
{
	std::cout << "The input is working!" << std::endl;
}

void Engine::SetStartState()
{
	m_xStateManager->QueueStateForChange(StateManager::STARTSTATE);
}

void Engine::SetMenuState()
{
	m_xStateManager->QueueStateForChange(StateManager::MENUSTATE);
}

void Engine::SetOptionState()
{
	m_xStateManager->QueueStateForChange(StateManager::OPTIONSTATE);
}