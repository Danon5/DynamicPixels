#include "SpriteManager.h"

void SpriteManager::DrawEntitySprites(sf::RenderWindow* renderWindow) const
{
	for (sf::Sprite entitySprite : _entitySprites)
		renderWindow->draw(entitySprite);
}

void SpriteManager::DrawChunkSprites(sf::RenderWindow* renderWindow) const
{
	for (sf::Sprite chunkSprite : _chunkSprites)
		renderWindow->draw(chunkSprite);
}