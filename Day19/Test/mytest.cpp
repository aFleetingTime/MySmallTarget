#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

int main()
{
	system("./mytest.exe");

	while (true)
	{
		if (_getch() == 'q')
			break;
	}

	return 0;
}