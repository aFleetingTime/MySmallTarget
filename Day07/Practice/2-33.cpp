#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main(int argv, char *argc[])
{
	int i = 0, &r = i;
	auto a = r;

	const int ci = i, &cr = ci;
	auto b = ci;
	auto c = cr;
	auto d = &i;
	auto e = &ci;

	const auto f = ci;

	auto &g = ci;
	const auto &h = 42;
	const auto &j = 42;

	a = 42;	//int
	cout << "a type: " << typeid(a).name() << endl;
	b = 42; //int
	cout << "b type: " << typeid(b).name() << endl;
	c = 42; //int
	cout << "c type: " << typeid(c).name() << endl;
	*d = 42;//int *
	cout << "d type: " << typeid(d).name() << endl;
	//*e = 42; //const int *
	cout << "e type: " << typeid(e).name() << endl;
	//g = 42; //const int &
	cout << "g type: " << typeid(g).name() << endl;

	system("pause");
	return 0;
}