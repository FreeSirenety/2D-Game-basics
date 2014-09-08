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
	static DebugManager& GetInstance()
	{
		static DebugManager instance;

		return instance;
	}

	void Update(float p_fDeltaTime);

	void CreateDebugMessage(std::string p_xStringToWrite, MessageType p_xMessageType);

private:
	DebugManager();

	DebugManager(DebugManager const& copy);
	DebugManager& operator=(DebugManager const& copy);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	std::vector<TextObject*> m_vTextObjects;
};