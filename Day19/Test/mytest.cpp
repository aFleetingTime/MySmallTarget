#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <memory>
#include <Windows.h>

using namespace std;

class Test
{
public:
	Test()
	{
		t = new int();
	}
	int test()
	{
		void **v = nullptr;
	}
	~Test()
	{
		cout << "..." << *t << endl;
		delete t;
		system("pause");
	}

private:
	int *t;
};

int main()
{
	auto_ptr<Test> a(new Test());
	cout << "???" << endl;
	a.release();
	while (true)
	{
		if (_getch() == 'q')
			break;
	}

	return 0;
}