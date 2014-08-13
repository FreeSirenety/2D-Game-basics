#include "DrawManager.h"
#include "Object.h"

DrawManager::DrawManager(sf::RenderWindow *p_xWindow)
{
	m_xWindow = p_xWindow;
}

void DrawManager::DrawDrawable(sf::Drawable *p_xDrawable)
{
	if (p_xDrawable != nullptr)
	{
		m_xWindow->draw(*p_xDrawable);
	}
}

void DrawManager::DrawObjectVector(std::vector<Object*> p_xObjectVector)
{
	for (auto object : p_xObjectVector)
	{
		if (object != nullptr)
		{
			m_xWindow->draw(*object);
		}
	}
}