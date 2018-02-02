#include <string>
#include <iostream>
#include <ctime>
#include <random>
#include <functional>

using namespace std;

#define MAX_SIZE 100000

class Sort
{
public:
	template<class T>
	void bubbleSort(T array, size_t length)
	{
		for (size_t i = 0, f = 1; i < length - 1 && f; ++i)
		{
			f = 0;
			for (size_t j = 0; j < length - i - 1; ++j)
			{
				if (array[j] > array[j + 1])
				{
					swap(&array[j + 1], &array[j]);
					f = 1;
				}
			}
		}
	}
	template<class T>
	void swap(T *a, T *b)
	{
		T temp = *a;
		*a = *b;
		*b = temp;
	}
};

template<class T>
void print_array(T array, int length)
{
	for (int i = 0; i < length; ++i)
		cout << array[i] << ' ';
	cout << endl;
}

int main()
{
	Sort sort;
	random_device random;
	int array[MAX_SIZE]{};
	for (int &val : array)
		val = random() % MAX_SIZE;

	//print_array(array, MAX_SIZE);
	clock_t s = clock();
	sort.bubbleSort(array, MAX_SIZE);
	cout << "ÓÃÊ±:" << clock() - s << endl;
	//print_array(array, MAX_SIZE);

	system("pause");
	return 0;
}