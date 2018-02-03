#include <string>
#include <iostream>
#include <ctime>
#include <random>
#include <array>
#include <functional>

using namespace std;

#define MAX_SIZE 100000
#define MIN_SIZE 10

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
	void selectionSort(T array, size_t length)
	{
		for (size_t i = 0, maxIndex = 0; i < length - 1; ++i)
		{
			maxIndex = i;
			for (size_t j = i + 1; j < length; ++j)
			{
				if (array[j] < array[maxIndex])
				{
					maxIndex = j;
				}
			}
			if (maxIndex != i)
			{
				swap(&array[i], &array[maxIndex]);
			}
		}
	}

	template<class T>
	void insertSort(T *array, size_t length)
	{
		for (size_t i = 1; i < length; ++i)
		{
			if (array[i] < array[i - 1])
			{
				size_t j = i - 1;
				T temp = array[i];
				for (;j >= 0 && array[j] > temp; --j)
				{
					array[j + 1] = array[j];
				}
				array[j + 1] = temp;
			}
		}
	}

	template<class T>
	void shellsSort(T *array, size_t length)
	{
		size_t increasement = length;
		do
		{
			increasement = increasement / 3 + 1;
			for (size_t i = 0; i < increasement; ++i)
			{
				for (size_t j = i + increasement; j < length; j += increasement)
				{
					if (array[j] < array[j - increasement])
					{
						int k = j - increasement;
						T temp = array[j];
						for (; k >= 0 && array[k] > temp; k -= increasement)
						{
							array[k + increasement] = array[k];
						}
						array[k + increasement] = temp;
					}
				}
			}
		} while (increasement > 1);
	}

	template<class T>
	void shellsSort2(T *array, size_t length)
	{
		size_t gap = length / 3 + 1;
		do
		{
			gap = gap / 3 + 1;
			for (size_t i = gap; i < length; i++)
			{
				int k = i;
				T temp = array[i];
				for (int j = i - gap; j >= 0 && array[j] > temp; j -= gap)
				{
					array[j + gap] = array[j];
					k = j;
				}
				array[k] = temp;
			}
		} while (gap != 1);
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

int sum()
{
	return 0;
}
template<class T, class ...Args>
int sum(T num, Args... args)
{
	return num + sum(args...);
}

int sumx(initializer_list<int> args)
{
	initializer_list<int> argsa(args.begin() + 1, args.end());
	return *args.begin() + (argsa.size() ? sumx(argsa) : 0);
}

int main()
{
	random_device random;
	Sort sort;

	int array1[MAX_SIZE];
	int array2[MAX_SIZE];

	for (int i = 0; i < MAX_SIZE; ++i)
	{
		int temp = random() % MAX_SIZE;
		array1[i] = temp;
		array2[i] = temp;
	}

	clock_t s = clock();
	sort.shellsSort2(array1, MAX_SIZE);
	cout << "用时:" << clock() - s << endl;
	s = clock();
	sort.shellsSort(array2, MAX_SIZE);
	cout << "用时:" << clock() - s << endl;

	//print_array(array, MAX_SIZE);
	//clock_t s = clock() / CLOCKS_PER_SEC;
	//sort.bubbleSort(array, MAX_SIZE);
	//cout << "用时:" << clock() / CLOCKS_PER_SEC - s << endl;
	//print_array(array, MAX_SIZE);

	system("pause");
	return 0;
}