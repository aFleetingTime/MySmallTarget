#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include <iterator>


using namespace std;

template<typename T>
void print(T *array, int len)
{
	if (array == nullptr)
		return;

	for (int i = 0; i < len; i++)
		cout << array[i] << " ";
	cout << endl;
}

template <typename T> void selectSort(T *array, int len)
{
	if (array == nullptr || len <= 0)
		return;

	T temp = 0;
	int i = 0, j = 0, index = 0;

	for (int i = 0; i < len - 1; i++)
	{
		
		for (j = i + 1,index = i; j < len; j++)
		{
			if (array[j] < array[index])
				index = j;
		}
		if (i != index)
		{
			temp = array[index];
			array[index] = array[i];
			array[i] = temp;
		}
	}
}

int main(int argv, char *argc[])
{
	int arrayInt[] = { 10,68,96,45,62,45,77,41,100 };
	int lenInt = sizeof(arrayInt) / sizeof(*arrayInt);

	print(arrayInt, lenInt);

	selectSort(arrayInt, lenInt);

	print(arrayInt, lenInt);

	cout << "--------------------------" << endl;

	char arrayChar[] = { 'i','h','q','g','v','r','e','s','a' };
	int lenChar = sizeof(arrayChar) / sizeof(*arrayChar);

	print(arrayChar, lenChar);

	selectSort(arrayChar, lenChar);

	print(arrayChar, lenChar);

	system("pause");
	return 0;
}