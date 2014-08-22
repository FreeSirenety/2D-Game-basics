#pragma once

#include "SFML/Graphics.hpp"
#include <vector>

class GameObject;

class DrawManager
{

public:
	DrawManager(sf::RenderWindow *p_xWindow);

	void DrawDrawable(sf::Drawable *p_xDrawable);

	void DrawObjectVector(std::vector<GameObject*> p_xObjectVector);

private:
	sf::RenderWindow *m_xWindow;

};