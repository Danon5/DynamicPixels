#pragma once
#include "WindowManager.h"

class Engine
{
private:
	WindowManager* _windowManager;
public:
	Engine();
	~Engine();
	WindowManager* GetWindowManager() const;
private:
	void Run();
};