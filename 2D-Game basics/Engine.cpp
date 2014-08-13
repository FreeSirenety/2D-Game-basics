#include "Engine.h"
#include "InputHandler.h"
#include <iostream>
#include "StateManager.h"

Engine::Engine()
{
	m_xMainWindow = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
}

void Engine::Run()
{
	InputHandler *inputHandler = new InputHandler();

	inputHandler->MapFunctionToInput(InputHandler::FORWARD, std::bind(&Engine::TestInput, this));
	inputHandler->MapInputToKey(sf::Keyboard::W, InputHandler::FORWARD);

	while (m_xMainWindow->isOpen())
	{
		sf::Event event;
		while (m_xMainWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_xMainWindow->close();

			if (event.type == sf::Event::KeyPressed)
				inputHandler->RunFunctionFromKey(event.key.code);

			if (event.type == sf::Event::MouseButtonPressed)
				inputHandler->RebindOnNextKeyEvent(InputHandler::FORWARD);

		}

		m_xMainWindow->clear();
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

void SetStartState();

void SetMenuState();

void SetOptionState();