#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include <iterator>


using namespace std;

class Test1
{
public:
	virtual void fun();
};

class Test2 : public Test1
{
public:
	virtual void fun()
	{
		cout << "Test2 fun()" << endl;
	}
};

int main(int argv, char *argc[])
{
	Test2 t;
	t.fun();

	system("pause");
	return 0;
}