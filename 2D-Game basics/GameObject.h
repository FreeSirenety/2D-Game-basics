// GameObject.h
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class GameObject : public sf::Drawable
{
public:
	GameObject();
	~GameObject();
	void SetGameObject(sf::Vector2f p_xPos, float p_fWidth, float p_fHeight, sf::Sprite *p_xSprite);
	void SetPos(sf::Vector2f p_xPos);
	void SetWidth(float p_fWidth);
	void SetHeight(float p_fHeight);
	void SetSprite(sf::Sprite *p_xSprite);

	sf::Vector2f GetPos();
	float GetWidth();
	float GetHeight();
	sf::Sprite* GetSprite();

private:
	sf::Vector2f m_xPos;
	float m_fHeight;
	float m_fWidth;
	sf::Sprite* m_xSprite;
	virtual void Draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(*m_xSprite, states);
	}

};

