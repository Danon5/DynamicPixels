#include "Engine.h"

Engine::Engine()
{
	_windowManager = new WindowManager();
	Run();
}

Engine::~Engine()
{
	delete _windowManager;
}

void Engine::Run()
{
	sf::RenderWindow* window = _windowManager->GetRenderWindow();

	while (window->isOpen())
	{
		_windowManager->PopWindowEvents();

		window->clear();



		window->display();
	}
}

WindowManager* Engine::GetWindowManager() const
{
	return _windowManager;
}