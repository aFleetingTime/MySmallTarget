#include <string>
#include <iostream>
#include <ctime>
#include <random>
#include <array>
#include <functional>

using namespace std;

#define MAX_SIZE 10
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
	void quickSort(T *array, int start, int end)
	{
		if (start >= end)
			return;
		T num = array[start];
		int i = start, j = end;
		while (i < j)
		{
			while (i < j && array[j] >= num)
				--j;
			array[i] = array[j];
			while (i < j && array[i] <= num)
				++i;
			array[j] = array[i];
		}
		array[i] = num;
		quickSort(array, start, i - 1);
		quickSort(array, j + 1, end);
	}

	template<class T>
	void myMerge(T *array, int start, int end)
	{
		int left_i = start, right_i = (start + end) / 2;
		int left_j = (start + end) / 2 + 1, right_j = end;
		int bufIndex = 0;
		int *buf = new int[end - start + 1];
		while (left_i <= right_i && left_j <= right_j)
		{
			if (array[left_i] > array[left_j])
				buf[bufIndex++] = array[left_j++];
			else
				buf[bufIndex++] = array[left_i++];
		}
		while (left_i <= right_i)
			buf[bufIndex++] = array[left_i++];
		while (left_j <= right_j)
			buf[bufIndex++] = array[left_j++];
		for (bufIndex = 0; start <= end; ++bufIndex, ++start)
			array[start] = buf[bufIndex];
		delete[] buf;
	}

	template<class T>
	void mergeSort(T *array, int start, int end)
	{
		if (start >= end)
			return;
		int mid = (start + end) / 2;
		mergeSort(array, start, mid);
		mergeSort(array, mid + 1, end);
		myMerge(array, start, end);
	}

	template<class T>
	void initHeap(T *array, int length)
	{
		int index = length / 2;
		while (index != -1)
		{
			if (array[index] < array[index * 2])
				swap(&array[index], &array[index * 2]);
			if (array[index] < array[index * 2 + 1])
				swap(&array[index], &array[index * 2 + 1]);
			--index;
		}
	}

	template<class T>
	void heapSort(T *array, int length)
	{
		if (!length)
			return;
		swap(&array[0], &array[length]);
		int end = length / 2;
		for (int i = 0; i < end; ++i)
		{
			if (array[i] < array[i * 2])
				swap(&array[i], &array[i * 2]);
			if (array[i] < array[i * 2 + 1])
				swap(&array[i], &array[i * 2 + 1]);
		}
		heapSort(array, length - 1);
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
void print_array(T *array, int length)
{
	for (int i = 0; i < length; ++i)
	{
		cout << array[i] << ' ';
	}
	cout << endl;
}

int main()
{
	random_device random;
	Sort sort;

	int *array1 = new int[MAX_SIZE];

	for (int i = 0; i < MAX_SIZE; ++i)
	{
		array1[i] = random() % MAX_SIZE;
	}

	clock_t s = clock();
	//print_array(array1, MAX_SIZE);
	print_array(array1, MAX_SIZE);
	//sort.mergeSort(array1, 0, MAX_SIZE - 1);
	//sort.quickSort(array1, 0, MAX_SIZE - 1);
	sort.initHeap(array1, MAX_SIZE - 1);
	sort.heapSort(array1, MAX_SIZE - 1);
	print_array(array1, MAX_SIZE);
	cout << "用时:" << clock() - s << endl;

	delete[] array1;
	//print_array(array, MAX_SIZE);
	//clock_t s = clock() / CLOCKS_PER_SEC;
	//sort.bubbleSort(array, MAX_SIZE);
	//cout << "用时:" << clock() / CLOCKS_PER_SEC - s << endl;
	//print_array(array, MAX_SIZE);

	system("pause");
	return 0;
}