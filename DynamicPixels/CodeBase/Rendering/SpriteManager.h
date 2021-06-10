#pragma once
#include "SFML/Graphics.hpp"
#include <list>

class SpriteManager
{
public:
private:
	std::list<sf::Sprite> _entitySprites;
	std::list<sf::Sprite> _chunkSprites;
public:
	void DrawEntitySprites(sf::RenderWindow* renderWindow) const;
	void DrawChunkSprites(sf::RenderWindow* renderWindow) const;
private:
};