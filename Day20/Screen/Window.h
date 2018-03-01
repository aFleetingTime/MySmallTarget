#pragma once
#include <vector>

class Screen;

class Window
{
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clearScreen(ScreenIndex index);
	ScreenIndex addScreen(Screen *s);

private:
	std::vector<Screen*> mScreens;
};