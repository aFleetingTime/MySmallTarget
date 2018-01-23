#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Test
{
public:
	~Test()
	{
		cout << "~Test()" << endl;
	}
};
void deque_efficiency()
{
	deque<int> d;
	clock_t s_time = 0, e_time = 0;

	s_time = clock();
	for (int i = 0; i < 1000000; ++i)
	{
		d.push_front(i);
	}
	for (int i = 0; i < 1000000; ++i)
	{
		d.pop_front();
	}
	e_time = clock();

	cout << "deque time:" << e_time - s_time << endl;
}
void vector_efficiency()
{
	vector<int> d;
	clock_t s_time = 0, e_time = 0;

	s_time = clock();
	//d.reserve(1000000);
	for (int i = 0; i < 1000000; ++i)
	{
		d.push_back(i);
	}
	for (int i = 0; i < 1000000; ++i)
	{
		d.pop_back();
	}
	e_time = clock();

	cout << "vector time:" << e_time - s_time << endl;
}

int main()
{
	vector_efficiency();
	deque_efficiency();

	system("pause");
	return 0;
}