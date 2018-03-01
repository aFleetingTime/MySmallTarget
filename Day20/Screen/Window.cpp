#include "Window.h"
#include "Sereen.h"
#include <string>

void Window::clearScreen(ScreenIndex index)
{
	Screen *scr = mScreens.at(index);
	if (scr == nullptr)
		return;
	scr->mScreen = std::string(scr->mHeight * scr->mWidth, ' ');
}

Window::ScreenIndex Window::addScreen(Screen *s)
{
	mScreens.push_back(s);
	return mScreens.size() - 1;
}