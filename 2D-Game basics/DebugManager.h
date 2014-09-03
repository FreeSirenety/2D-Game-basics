#pragma once

#include "SFML/Graphics.hpp"
#include <string>
#include <vector>

class TextObject;

class DebugManager : public sf::Drawable
{

public:
	enum MessageType
	{
		WARNING,
		ALERT,
		LOG
	};

public:
	DebugManager();

	void Update(float p_fDeltaTime);

	void CreateDebugMessage(std::string p_xStringToWrite, MessageType p_xMessageType);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	std::vector<TextObject*> m_vTextObjects;
};