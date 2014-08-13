#pragma once

#include "SFML/Graphics.hpp"

#include <functional>
#include <vector>

class AnimatedSprite : public sf::Sprite
{
public:

	struct Frame
	{
	public:
		Frame(sf::Sprite p_xSprite, float p_fDuration, bool p_bHasFunction = false, std::function<void()> p_fFunction = NULL)
		{
			m_xSprite = p_xSprite;
			m_fDuration = p_fDuration;
			m_bHasFunction = p_bHasFunction;
			m_fFunction = p_fFunction;
		};

		sf::Sprite m_xSprite;
		float m_fDuration;
		bool m_bHasFunction;
		std::function<void()> m_fFunction;
	};

public:

private:


};