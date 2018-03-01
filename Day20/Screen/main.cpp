#include "Sereen.h"

int main()
{
	Screen s(5, 5, 'X');
	s.move(4, 0).set('#').desplay(std::cout);
	std::cout << '\n' << std::endl;
	s.desplay(std::cout);
	std::cout << std::endl;

	system("pause");

	return 0;
}