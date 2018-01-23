#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

void test()
{
	list<int> l;
	for (int i = 0; i < 10; i++)
	{
		l.push_back(rand() % 200);
	}
	l.sort();
	//sort(l.begin(), l.end());
	for (auto t : l)
	{
		cout << t << " " << endl;
	}
}

int main()
{
	test();

	system("pause");
	return 0;
}