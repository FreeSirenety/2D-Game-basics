#include "DebugManager.h"
#include "TextObject.h"
#include <iostream>

DebugManager::DebugManager()
{
	
}

void DebugManager::CreateDebugMessage(std::string p_xStringToWrite, MessageType p_xMessageType)
{
	sf::Font font;
	font.loadFromFile("arial.ttf");

	if (m_vTextObjects.size() > 300)
	{
		auto iter = m_vTextObjects.begin();
		iter++;

		delete *iter;

		m_vTextObjects.erase(iter);
	}

	switch (p_xMessageType)
	{
	case WARNING:
		p_xStringToWrite = "[WARNING]: " + p_xStringToWrite;
		break;

	case ALERT:
		p_xStringToWrite = "[ALERT]: " + p_xStringToWrite;
		break;

	case LOG:
		p_xStringToWrite = "[LOG]: " + p_xStringToWrite;
		break;

	default:
		break;
	}

	TextObject *text = new TextObject(p_xStringToWrite, font, 20);

	switch (p_xMessageType)
	{
	case WARNING:
		text->SetColor(sf::Color::Red);
		break;

	case ALERT:
		text->SetColor(sf::Color::Yellow);
		break;

	case LOG:
		text->SetColor(sf::Color::White);
		break;

	default:
		break;
	}

	m_vTextObjects.push_back(text);
}

void DebugManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	int spacing = 30;
	int i = 0;

	for (int i = 1; i < 10; i++)
	{
		if (i > m_vTextObjects.size())
			break;

		m_vTextObjects[m_vTextObjects.size() - i]->SetPosition(sf::Vector2f(spacing, spacing * (i - 1) + spacing));

		target.draw(*m_vTextObjects[m_vTextObjects.size() - i]);

	}
}

void DebugManager::Update(float p_fDeltaTime)
{
	std::cout << "The debug manager is updating and the entered number is: " << p_fDeltaTime << std::endl;
}