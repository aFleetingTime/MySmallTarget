#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <ctime>

using namespace std;

template<class T1, class T2>
int Compare(T1 a, T2 b)
{
	return (a < b) ? -1 : (a > b ? 1 : 0);
}

template<class T, class E_TYPE>
void QuickSort(T array, int i, int j)
{
	if (i >= j)
		return;
	E_TYPE num = array[i];
	int index = i;
	int mI = i, mJ = j;
	while (mI < mJ)
	{
		while (mI < mJ && index == mI)
		{
			if (array[mJ] < num)
			{
				array[mI] = array[mJ];
				index = mJ;
				break;
			}
			--mJ;
		}
		while(mI < mJ && index == mJ)
		{
			if (array[mI] > num)
			{
				array[mJ] = array[mI];
				index = mI;
				break;
			}
			++mI;
		}
	}
	array[mI] = num;
	QuickSort<T, E_TYPE>(array, i, mI - 1);
	QuickSort<T, E_TYPE>(array, mJ + 1, j);
}

void QuickSort1(vector<int> &array, int low, int high)
{
	if (low >= high)
		return;
	int num = array[low];
	int i = low, j = high;
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
	QuickSort1(array, low, i - 1);
	QuickSort1(array, j + 1, high);
}
void QuickSort1(int *array, int low, int high)
{
	if (low >= high)
		return;
	int num = array[low];
	int i = low, j = high;
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
	QuickSort1(array, low, i - 1);
	QuickSort1(array, j + 1, high);
}


#define SIZE 100000

int main()
{
	random_device random;
	vector<int> ivec;
	clock_t s = 0;

	//int *array1 = new int[SIZE];
	//int *array2 = new int[SIZE];
	int array1[SIZE];
	int array2[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		array1[i] = random() % SIZE + 1;
		array2[i] = random() % SIZE + 1;
	}
	//for (int i = 0; i < SIZE; ++i)
	//{
	//	ivec.push_back(random() % SIZE + 1);
	//}

	s = clock();
	QuickSort1(array2, 0, SIZE - 1);
	cout << "QuickSort1用时:" << clock() - s << "ms" << endl;

	s = clock();
	QuickSort<int*, int>(array1, 0, SIZE - 1);
	cout << "QuickSort用时:" << clock() - s << "ms" << endl;


	cout << endl;
	
	//s = clock();
	//QuickSort<vector<int>&, int>(ivec, 0, ivec.size() - 1);
	//cout << "QuickSort用时:" << clock() - s << "ms" << endl;

	//s = clock();
	//QuickSort1(ivec, 0, ivec.size() - 1);
	//cout << "QuickSort1用时:" << clock() - s << "ms" << endl;
	//
	//cout << endl;

	//delete array1;
	//delete array2;
	
	system("pause");
	return 0;
}