#pragma once

#include <SFML/Graphics.hpp>

class StateManager;
class DrawManager;
class SpriteManager;

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

	StateManager *m_xStateManager;

	DrawManager *m_xDrawManager;

	SpriteManager *m_xSpriteManager;

};