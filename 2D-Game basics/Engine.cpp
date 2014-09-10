#include "Engine.h"
#include "InputHandler.h"
#include <iostream>
#include "StateManager.h"
#include "DrawManager.h"
#include "SpriteManager.h"
#include "DebugManager.h"

Engine::Engine()
{
	m_xMainWindow = new sf::RenderWindow(sf::VideoMode(1920, 1080), "SFML works!");

	m_xDrawManager = new DrawManager(m_xMainWindow);

	m_xSpriteManager = new SpriteManager("");

	m_xStateManager = new StateManager(m_xDrawManager, m_xSpriteManager);

	DebugManager::GetInstance().CreateDebugMessage("Test1", DebugManager::ALERT);
	DebugManager::GetInstance().CreateDebugMessage("Test2", DebugManager::ALERT);
	DebugManager::GetInstance().CreateDebugMessage("Test3", DebugManager::ALERT);
}

void Engine::Run()
{

	sf::Clock clock;
	while (m_xMainWindow->isOpen())
	{
		m_xMainWindow->clear();
		sf::Event event;
		while (m_xMainWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_xMainWindow->close();

			if (event.type == sf::Event::KeyPressed)
				m_xStateManager->HandleEvent(event.key.code, true);

			if (event.type == sf::Event::KeyReleased)
				m_xStateManager->HandleEvent(event.key.code, false);

			/*if (event.type == sf::Event::MouseButtonPressed)
				inputHandler->RebindOnNextKeyEvent(InputHandwaler::FORWARD);*/

		}

		m_xStateManager->Update(clock.restart().asSeconds());

		m_xMainWindow->draw(DebugManager::GetInstance());

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