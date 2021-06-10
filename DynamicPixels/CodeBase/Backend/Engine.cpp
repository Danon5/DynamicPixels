#include "Engine.h"

Engine::Engine()
{
	_renderWindowManager = new RenderWindowManager();
	_spriteManager = new SpriteManager();
	Run();
}

Engine::~Engine()
{
	delete _renderWindowManager;
}

void Engine::Run()
{
	sf::RenderWindow* window = _renderWindowManager->GetRenderWindow();

	while (window->isOpen())
	{
		_renderWindowManager->PopWindowEvents();

		_renderWindowManager->ClearFrame();

		_spriteManager->DrawChunkSprites(window);
		_spriteManager->DrawEntitySprites(window);

		_renderWindowManager->DrawFrame();
	}
}

RenderWindowManager* Engine::GetWindowManager() const
{
	return _renderWindowManager;
}

SpriteManager* Engine::GetSpriteManager() const
{
	return _spriteManager;
}