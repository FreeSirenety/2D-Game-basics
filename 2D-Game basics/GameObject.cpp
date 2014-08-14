// GamObject.cpp

#include "GameObject.h"


GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

void GameObject::SetGameObject(sf::Vector2f p_xPos, float p_fWidth, float p_fHeight, sf::Sprite* p_xSprite)
{
	m_xPos = p_xPos;	
	m_fWidth = p_fWidth;
	m_fHeight = p_fHeight;
	m_xSprite = p_xSprite;

}

void GameObject::SetPos(sf::Vector2f p_xPos)
{
	m_xPos = p_xPos;
}

void GameObject::SetWidth(float p_fWidth)
{
	m_fWidth = p_fWidth;
}

void GameObject::SetHeight(float p_fHeight)
{
	m_fHeight = p_fHeight;
}

void GameObject::SetSprite(sf::Sprite *p_xSprite)
{
	m_xSprite = p_xSprite;
}

sf::Vector2f GameObject::GetPos()
{
	return m_xPos;
}

float GameObject::GetWidth()
{
	return m_fWidth;
}

float GameObject::GetHeight()
{
	return m_fHeight;
}

sf::Sprite* GameObject::GetSprite()
{
	return m_xSprite;
}
