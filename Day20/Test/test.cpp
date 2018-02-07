#include <iostream>
#include <iterator>
#include <random>

using namespace std;

constexpr int x = 5, y = 10;
random_device random;

void initArray(int (*p)[y])
{
	for (int (*t)[y] = p; t != p + x; ++t)
	{
		for (int *a = *t; a != *t + y; ++a)
			*a = random() % 50;
	}
}

void test1(int (*const &p)[10])
{
	//for(int (*a)[y] : p)
	for (const auto &s : p)
	{
		for (auto a : s)
			cout << a << ' ';
		cout << endl;
	}
}

int main()
{
	int array[x][y]{};
	initArray(array);
	test1(array);
	for (const auto &p : array)
	{
		for (auto a : p)
			cout << a << ' ';
		cout << endl;
	}

	system("pause");
	return 0;
}