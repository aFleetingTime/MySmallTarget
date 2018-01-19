#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include <iterator>


using namespace std;

int& func()
{
	int *temp = new int;
	return *temp;
}

int main(int argv, char *argc[])
{
	int &test = func();
	test = 1000;
	cout << "Test:" << test << endl;

	system("pause");
	return 0;
}