#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include <iterator>
#include "TestPerson.cpp"

using namespace std;


int main(int argv, char *argc[])
{
	TestPerson<int> per(10, 20);
	per.show();
	print(per);

	TestPerson<char> pers(65, 66);
	pers.show();
	print(pers);
	
	system("pause");
	return 0;
}