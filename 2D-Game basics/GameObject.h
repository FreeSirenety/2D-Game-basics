// GameObject.h

#include "Object.h"
#include <SFML/Graphics.hpp>

class GameObject : public sf::Drawable, public Object
{
public:
	GameObject();
	~GameObject();

	virtual void Update(float p_fDeltaTime);

	void SetGameObject(sf::Vector2f p_xPos, float p_fWidth, float p_fHeight, sf::Sprite *p_xSprite);
	void SetPos(sf::Vector2f p_xPos);
	void SetWidth(float p_fWidth);
	void SetHeight(float p_fHeight);
	void SetSprite(sf::Sprite *p_xSprite);

	sf::Vector2f GetPos();
	float GetWidth();
	float GetHeight();
	sf::Sprite* GetSprite();

	
protected:
	sf::Vector2f m_xPos;
	float m_fHeight;
	float m_fWidth;
	sf::Sprite* m_xSprite;

private:
	
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(*m_xSprite, states);
	}

};

