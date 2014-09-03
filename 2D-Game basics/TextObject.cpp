#include "TextObject.h"

TextObject::TextObject(std::string p_sString, sf::Font p_xFont, int p_iFontSize)
{
	m_sText = p_sString;
	m_xFont = p_xFont;
	m_iSize = p_iFontSize;
	m_xColor = sf::Color::White;

	m_xText = sf::Text(m_sText, m_xFont, m_iSize);

	m_xText.setColor(m_xColor);
}

void TextObject::SetColor(sf::Color p_xColor)
{
	m_xColor = p_xColor;

	m_xText.setColor(m_xColor);
}

void TextObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_xText);
}