#include "Sereen.h"

Screen::Screen(pos_t h, pos_t w, char c) : mHeight(h), mWidth(w), mScreen(h * w, c) {}

Screen &Screen::move(pos_t r, pos_t c)
{
	mCursor = r * mWidth + c;
	return *this;
}

Screen &Screen::set(char ch)
{
	mScreen.at(mCursor) = ch;
	return *this;
}

Screen &Screen::set(pos_t r, pos_t c, char ch)
{
	mScreen.at(r * mWidth + c) = ch;
	return *this;
}

char Screen::get() const
{
	return mScreen.at(mCursor);
}

char Screen::get(pos_t r, pos_t c) const
{
	return mScreen.at(r * mWidth + c);
}

Screen &Screen::desplay(std::ostream &os)
{
	doDisplay(os);
	return *this;
}

const Screen &Screen::desplay(std::ostream &os) const
{
	doDisplay(os);
	return *this;
}