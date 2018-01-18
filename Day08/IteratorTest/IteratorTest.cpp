#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <vector>
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
	stime = clock();
	for (auto beg = vec.begin(), end = vec.end(); beg != end; ++beg)
	{
		++(*beg);
		//--(*beg);
	}
	etime = clock();
	cout << "Iterator Time:" << etime - stime << endl;

	system("pause");
	return 0;
}