#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include <iterator>


using namespace std;

template<typename T>
void MySwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

class Test1
{

};

class Test2 : public Test1
{

};

template<class T>
void func(T *p)
{
	cout << p << endl;
	delete p;
}

int main(int argv, char *argc[])
{
	int a = 10, b = 20;
	MySwap<int>(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	MySwap(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	func<Test1>(new Test1);

	system("pause");
	return 0;
}