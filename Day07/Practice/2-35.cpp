#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main(int argv, char *argc[])
{
	const int i = 42;
	auto j = i;	//int
	cout << "j type: " << typeid(j).name() << endl;
	const auto &k = i;	//const int &
	auto *p = &i; //const int *
	cout << "p type: " << typeid(p).name() << endl;
	const auto j2 = i; //const int
	cout << "j2 type: " << typeid(j2).name() << endl;
	const auto &k2 = i; //const int &
	cout << "k2 type: " << typeid(k2).name() << endl;

	system("pause");
	return 0;
}