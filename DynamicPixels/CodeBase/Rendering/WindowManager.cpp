#include "WindowManager.h"

WindowManager::WindowManager()
{
	InitializeWindow(800, 600);
}

WindowManager::~WindowManager()
{
	delete _renderWindow;
}

void WindowManager::InitializeWindow(int width, int height)
{
	_renderWindow = new sf::RenderWindow(sf::VideoMode(width, height), "DynamicPixels");
	_renderWindow->setFramerateLimit(60);
}

void WindowManager::SetResolution(int width, int height)
{
	sf::Vector2u newSize(width, height);
	_renderWindow->setSize(newSize);
}

void WindowManager::PopWindowEvents()
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

sf::RenderWindow* WindowManager::GetRenderWindow() const
{
	return _renderWindow;
}