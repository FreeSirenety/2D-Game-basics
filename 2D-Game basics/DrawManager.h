#pragma once

#include "SFML/Graphics.hpp"
#include <vector>

class Object;

class DrawManager : public sf::Drawable
{

public:
	DrawManager(sf::RenderWindow *p_xWindow);

	void DrawDrawable(sf::Drawable *p_xDrawable);

	void DrawObjectVector(std::vector<Object*> p_xObjectVector);

private:
	sf::RenderWindow *m_xWindow;

};