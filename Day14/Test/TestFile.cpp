#include <vector>
#include <iostream>
#include <iterator>
#include <functional>
#include <algorithm>
#include <set>
#include <list>
#include <deque>
//#include <std>

using namespace std;

class Test
{
public:
	Test(int age)
	{
		mAge = age;
	}
public:
	int mAge;
};

template<class T>
struct MyPrint
{
	void operator()(T &a)
	{
		cout << a << " ";
	}
};

void test1()
{
	int a1[] = { 1,2,8,100};
	int a2[] = { 1,2,5,9 };
	multiset<int> ivec1(begin(a1), end(a1));
	multiset<int> ivec2(begin(a2), end(a2));
	vector<int> ivec3;
	ivec3.resize(ivec1.size());
	set_intersection(ivec1.begin(), ivec1.end(), ivec2.begin(), ivec2.end(), ivec3.begin());
	transform(ivec3.begin(), ivec3.end(), ostream_iterator<int>(cout, " "), bind2nd(plus<int>(), 0));
}

void test2()
{
	list<int> l;
	deque<int> s;
	for (int i = 0; i < 10; ++i)
	{
		l.push_back(i);
		s.push_back(i);
	}
	//random_shuffle(l.begin(), l.end());	random_shuffle不支持无法随机访问的容器
	for_each(s.begin(), s.end(), MyPrint<int>());
	cout << endl;
	random_shuffle(s.begin(), s.end());
	for_each(s.begin(), s.end(), MyPrint<int>());
	cout << endl;
}

int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}