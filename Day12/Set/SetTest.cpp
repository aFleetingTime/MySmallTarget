#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iomanip>

using namespace std;

void set_test_1()
{
	set<int> iset;
	for (int i = 0; i < 10; i++)
	{
		iset.insert(i);
	}
	pair<set<int>::iterator, set<int>::iterator> equal = iset.equal_range(4);

	if (equal.first != iset.end())
		cout << setiosflags(ios::right) << setw(7) << "first:" << *equal.first << endl;
	if (equal.second != iset.end())
		cout << setiosflags(ios::right) << setw(7) << "second:" << *equal.second << endl;
}
int main()
{
	set_test_1();

	system("pause");
	return 0;
}