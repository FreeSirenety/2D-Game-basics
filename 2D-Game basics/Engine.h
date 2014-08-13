#pragma once

#include <SFML/Graphics.hpp>

class Engine
{

public:
	Engine();

	void Run();

	void Cleanup();

	void TestInput();

	void SetStartState();

	void SetMenuState();

	void SetOptionState();

private:
	sf::RenderWindow *m_xMainWindow;

};