#include "WindowManager.h"

RenderWindowManager::RenderWindowManager()
{
	InitializeWindow(800, 600);
}

RenderWindowManager::~RenderWindowManager()
{
	delete _renderWindow;
}

void RenderWindowManager::InitializeWindow(int width, int height)
{
	_renderWindow = new sf::RenderWindow(sf::VideoMode(width, height), "DynamicPixels");
	_renderWindow->setFramerateLimit(60);
}

void RenderWindowManager::SetResolution(int width, int height)
{
	sf::Vector2u newSize(width, height);
	_renderWindow->setSize(newSize);
}

void RenderWindowManager::PopWindowEvents()
{
	sf::Event evnt;

	while (_renderWindow->pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::Closed:
			_renderWindow->close();
		}
	}
}

void RenderWindowManager::ClearFrame()
{
	_renderWindow->clear();
}

void RenderWindowManager::DrawFrame()
{
	_renderWindow->display();
}

sf::RenderWindow* RenderWindowManager::GetRenderWindow() const
{
	return _renderWindow;
}