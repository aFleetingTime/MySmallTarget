#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	int count = 0;
	class a { public: bool operator()(string a, string b) { return a + b > b + a; } };
	multiset<string, a> mSort;
	int buf;
	while (cin >> count)
	{
		mSort.clear();
		for (int i = 0; i < count; ++i)
		{
			cin >> buf;
			mSort.emplace(to_string(buf));
		}
		string outStr;
		for (auto a : mSort)
		{
			cout << a;
		}
		cout << endl;
	}
	return 0;
}