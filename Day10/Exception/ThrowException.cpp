#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <exception>


using namespace std;

template<typename T>
T Divition(T a, T b)
{
	if (b == 0)
		throw new exception("除数不能为0");
	return a / b;
}

template<typename T>
T fun(T a, T b)
{
	return Divition(a, b);
	
}

//int Divition(int a, int b)
//{
//	if (b == 0)
//		throw new exception("除数不能为0");
//	return a / b;
//}
//
//int fun(int a, int b)
//{
//	return Divition(a, b);
//}

int main(int argv, char *argc[])
{
	try
	{
		int i = fun(1, 0);
		cout << "结果为:" << i << endl;
	}
	catch (exception *e)
	{
		cout << e->what() << endl;
		delete e;
	}

	system("pause");
	return 0;
}