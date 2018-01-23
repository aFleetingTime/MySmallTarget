#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iomanip>

using namespace std;

template<class T>
class MyCompare
{
public:
	bool operator()(T t1, T t2) const
	{
		return t1 > t2;
	}
};
class Test
{
public:
	Test(int age)
	{
		this->age = age;
	}
	bool operator<(const Test &t) const
	{
		return this->age > t.age;
	}
	int age;
};
template<class T1, class T2>
void print_set(set<T1, T2> &mSet)
{
	for (typename set<T1, T2>::iterator beg = mSet.begin(), End = mSet.end(); beg != End; ++beg)
	{
		cout << *beg << ' ';
	}
	cout << endl;
}
void set_test_1()
{
	set<int, MyCompare<int>> iset;
	for (int i = 0; i < 10; i++)
		iset.insert(i);
	print_set(iset);
	pair<set<int, MyCompare<int>>::iterator, set<int>::iterator> equal = iset.equal_range(4);
	if (equal.first != iset.end())
		cout << setiosflags(ios::right) << setw(7) << "first:" << *equal.first << endl;
	if (equal.second != iset.end())
		cout << setiosflags(ios::right) << setw(7) << "second:" << *equal.second << endl;
}
void set_test_2()
{
	set<Test> mSet;
	for (int i = 0; i < 10; ++i)
	{
		mSet.insert(Test(rand() % 200));
	}
	cout.setf(ios::left);
	for (set<Test>::iterator beg = mSet.begin(), End = mSet.end(); beg != End; ++beg)
	{
		cout.width(4);
		cout << beg->age;
	}
	cout << endl;
	cout.unsetf(ios::left);
}
int main()
{
	//set_test_1();
	set_test_2();

	system("pause");
	return 0;
}