#pragma once
#include "SFML/Graphics.hpp"

class WindowManager
{
private:
	sf::RenderWindow* _renderWindow;
	void InitializeWindow(int width, int height);
public:
	WindowManager();
	~WindowManager();
	void SetResolution(int width, int height);
	void PopWindowEvents();
	sf::RenderWindow* GetRenderWindow() const;
private:
};