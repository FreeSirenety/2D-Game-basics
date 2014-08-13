#include "SpriteManager.h"
#include <fstream>

SpriteManager::SpriteManager(std::string directory)
{
		m_sDirectoryPath = directory;
}

sf::Sprite *SpriteManager::loadSprite(std::string fileName, int x, int y, int w, int h)
{
	auto it = m_mTextures.find(fileName);

	if (it == m_mTextures.end())
	{
		sf::Texture *texture = new sf::Texture;

		texture->loadFromFile(m_sDirectoryPath + fileName, sf::IntRect(x, y, w, h));

		m_mTextures.insert(std::pair<std::string, sf::Texture*>(fileName, texture));

		it = m_mTextures.find(fileName);
	}

	return new sf::Sprite(*it->second);
}

sf::Sprite *SpriteManager::loadSprite(std::string p_sFilePath)
{
	std::fstream stream(m_sDirectoryPath + p_sFilePath);

	std::string sTexturePath;

	stream >> sTexturePath;

	auto it = m_mTextures.find(sTexturePath);

	if (it == m_mTextures.end())
	{
		sf::Texture *texture = new sf::Texture;

		texture->loadFromFile(m_sDirectoryPath + sTexturePath);

		m_mTextures.insert(std::pair<std::string, sf::Texture*>(sTexturePath, texture));

		it = m_mTextures.find(sTexturePath);
	}

	int x, y, w, h;

	stream >> x >> y >> w >> h;

	return new sf::Sprite(*it->second, sf::IntRect(x, y, w, h));
}