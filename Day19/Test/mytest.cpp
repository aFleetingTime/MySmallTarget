#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

class Test
{
public:
	int test()
	{
		void **v = nullptr;
	}

private:
	static int a;
};
int Test::a = 0;

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