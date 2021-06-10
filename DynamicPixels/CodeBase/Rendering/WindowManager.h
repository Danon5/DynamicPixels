#pragma once
#include "SFML/Graphics.hpp"

class RenderWindowManager
{
private:
	sf::RenderWindow* _renderWindow;
	void InitializeWindow(int width, int height);
public:
	RenderWindowManager();
	~RenderWindowManager();
	void SetResolution(int width, int height);
	void PopWindowEvents();
	void ClearFrame();
	void DrawFrame();
	sf::RenderWindow* GetRenderWindow() const;
private:
};