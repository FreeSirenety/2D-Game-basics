#pragma once

#include "SFML/Graphics.hpp"

#include <string>

class TextObject : public sf::Drawable
{
public:
	TextObject(std::string p_sString, sf::Font p_xFont, int p_iFontSize);

	void SetColor(sf::Color p_xColor);

	void SetPosition(sf::Vector2f p_xNewPosition);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	std::string m_sText;
	sf::Font m_xFont;
	int m_iSize;
	sf::Color m_xColor;

	sf::Text m_xText;

	sf::Vector2f m_xPosition;
};