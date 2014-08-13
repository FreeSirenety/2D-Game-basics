#pragma once

#include <string>

#include "SFML/Graphics.hpp"

class Object : public sf::Drawable
{
public:
	Object();

	void SetTag(std::string p_sTag);
	std::string GetTag();

private:
	std::string m_sTag;
};