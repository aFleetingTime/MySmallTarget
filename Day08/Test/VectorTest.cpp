#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include <iterator>


using namespace std;


int main(int argv, char *argc[])
{
	vector<int> ivec(11);
	int temp = 0;
	while (cin >> temp && temp >= 0)
	{
		if(temp <= 100)
			++ivec[temp / 10];
	}
	for (int i : ivec)
	{
		cout << i << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}