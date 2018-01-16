#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Test1
{
public:
	virtual void print()
	{
		cout << "Test1" << endl;
	}
	virtual void print(int i)
	{
		cout << "Test1:" << i << endl;
	}
	virtual void print(int i, int j)
	{
		cout << "Test1:" << i << ":" << j << endl;
	}
};

class Test2 : public Test1
{
public:
	virtual void print()
	{
		cout << "Test2" << endl;
	}
	virtual void print(int i)
	{
		cout << "Test2:" << i;
	}
	virtual void print(int i, int j)
	{
		cout << "Test2:" << i << ":" << j << endl;
	}
	virtual void print(int i, int j, int k)
	{
		cout << "Test2:" << i << ":" << j << ":" << k;
	}
};

int main(int argv, char *argc[])
{
	Test2 t2;
	t2.Test1::print();

	Test1 *pt1 = &t2;
	pt1->print(1, 2);

	t2.print(1, 2, 3);

	system("pause");
	return 0;
}