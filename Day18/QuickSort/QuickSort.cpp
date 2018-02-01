#include <iostream>

using namespace std;

template<class T1, class T2>
bool compare(T1 a, T2 b)
{
	return a < b;
}

template<class T, class E_TYPE>
void QuickSort(T array, int i, int j, bool(*comp)(E_TYPE, E_TYPE))
{
	if (i >= j)
		return;
	E_TYPE num = array[i];
	int index = i;
	int mI = i, mJ = j;
	//while (mI < mJ && array[mJ] >= num)
	//	--mJ;

	while (mI < mJ)
	{
		if (index == mI)
		{
			if (array[mJ] < num)
			{
				array[mI] = array[mJ];
				index = mJ;
			}
			else
			{
				--mJ;
			}
		}
		else
		{
			if (array[mI] > num)
			{
				array[mJ] = array[mI];
				index = mI;
			}
			else
			{
				++mI;
			}
		}
	}
	array[mI] = num;
	QuickSort(array, i, mI - 1, comp);
	QuickSort(array, mJ + 1, j, comp);
}

int main()
{
	int array[10] = { 1,5,9,4,6,3,2,8,0,7 };
	QuickSort(array, 0, sizeof(array) / sizeof(*array) - 1, compare<int,int>);
	for (int i = 0; i < 10; ++i)
	{
		cout << array[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}