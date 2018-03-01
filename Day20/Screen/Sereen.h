#include <iostream>
#include <string>

class Screen
{
public:
	using pos_t = std::string::size_type;
	Screen() = default;
	Screen(const pos_t h, const pos_t w, const char c);

	Screen &move(pos_t r, pos_t c);
	Screen &set(char ch);
	Screen &set(pos_t r, pos_t c, char ch);
	char get() const;
	char get(pos_t r, pos_t c) const;
	Screen &desplay(std::ostream &os);
	const Screen &desplay(std::ostream &os) const;

private:
	void doDisplay(std::ostream &os) const;
	pos_t mCursor = 0;
	pos_t mHeight = 0, mWidth = 0;
	std::string mScreen;
};

inline void Screen::doDisplay(std::ostream &os) const
{
	pos_t count = 0;
	for (const char &c : mScreen)
	{
		if (count++ == mWidth)
		{
			count = 1;
			os.put('\n');
		}
		os.put(c);
	}
}