#pragma once
#include "WindowManager.h"
#include "SpriteManager.h"

class Engine
{
private:
	RenderWindowManager* _renderWindowManager;
	SpriteManager* _spriteManager;
public:
	Engine();
	~Engine();
	RenderWindowManager* GetWindowManager() const;
	SpriteManager* GetSpriteManager() const;
private:
	void Run();
};