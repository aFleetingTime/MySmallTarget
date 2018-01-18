#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <cctype>
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include <iterator>


using namespace std;


int main(int argv, char *argc[])
{
	constexpr int COUNT = 100000000;
	vector<int> vec(COUNT);
	clock_t stime = 0;
	clock_t etime = 0;

	//~0.05s
	for (auto beg = vec.begin(), end = vec.end(); beg != end; ++beg)
	{
		++(*beg);
		--(*beg);
	}
	etime = clock();
	cout << "Iterator Time:" << etime - stime << endl;

	//~0.10s
	stime = clock();
	for (int i = 0; i < COUNT; ++i)
	{
		++vec[i];
		--vec[i];
	}
	etime = clock();
	cout << "Subscript Time:" << etime - stime << endl;
	stime = clock();

	

	system("pause");
	return 0;
}