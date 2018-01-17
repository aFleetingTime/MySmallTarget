#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main(int argv, char *argc[])
{
	int a = 3, b = 4;
	decltype(a) c = a;		//int c = 3
	decltype((b)) d = a;	//int &d = a;
	c++;					//c = 4;
	d++;					//&d(a) = 4;
	//a = 4, b = 4, c = 4, d = 4
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	system("pause");
	return 0;
}