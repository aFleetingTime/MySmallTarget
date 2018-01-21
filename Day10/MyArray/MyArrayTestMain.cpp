#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include <iterator>
#include "MyArray.hpp"

using namespace std;

void push_back(int &&a)
{
	cout << &a << endl;
}

int main(int argv, char *argc[])
{
	push_back(1);

#if 0
	MyArray<int> array(10);
	array[0] = 100;
	cout << array.getLength() << endl;
	cout << array[10] << endl;
	*(array + 1) = 1000;
	cout << *(array+1) << endl;
	*(array + 2) = 10010;
	cout << array << endl;

	cout << "----------------" << endl;

	MyArray<int> array2 = array;
	cout << array2 << endl;

	cout << "----------------" << endl;

	MyArray<int> array3(15);
	(array3 = array)[5] = 666;
	cout << array3 << endl;

	array2[9] = 999;
	array2 = array;
	cout << array2 << endl;
#endif

	system("pause");
	return 0;
}