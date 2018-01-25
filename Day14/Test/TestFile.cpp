#include <vector>
#include <iostream>
#include <iterator>
#include <functional>
#include <algorithm>
#include <set>
#include <list>
#include <deque>
#include <ctime>
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
struct Random
{
	void operator()(T &vessel, int num)
	{
		for (int i = 0; i < num; ++i)
			vessel.push_back(rand() % 100 + 1);
	}
};

template<class T>
struct MyPrint
{
	MyPrint(int num)
	{
		this->count = 0;
		this->mNum = num;
	}
	void operator()(T &a)
	{
		++count;
		cout << a << " ";
		if (mNum == count)
		{
			cout << endl;
			count = 0;
		}
	}
	int count;
	int mNum;
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
	for_each(s.begin(), s.end(), MyPrint<int>(s.size()));
	cout << endl;
	random_shuffle(s.begin(), s.end());
	for_each(s.begin(), s.end(), MyPrint<int>(s.size()));
	cout << endl;
}

void test3()
{
	vector<int> v1;
	vector<int> v2;

	Random<vector<int>>()(v1, 10);
	Random<vector<int>>()(v2, 10);

	cout << "拷贝前:" << endl;
	for_each(v2.begin(), v2.end(), MyPrint<int>(v2.size()));
	copy(v1.begin(),v1.end(),v2.begin());
	cout << "拷贝后:" << endl;
	for_each(v2.begin(), v2.end(), MyPrint<int>(v2.size()));

	v1.resize(0);
	Random<vector<int>>()(v1, 10);
	cout << "交换前:" << endl;
	for_each(v1.begin(), v1.end(), MyPrint<int>(v1.size()));
	for_each(v2.begin(), v2.end(), MyPrint<int>(v2.size()));
	swap(v1, v2);
	cout << "交换后:" << endl;
	for_each(v1.begin(), v1.end(), MyPrint<int>(v1.size()));
	for_each(v2.begin(), v2.end(), MyPrint<int>(v2.size()));
}

void test4()
{
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 4,5,6,7,8,9,10 };

	{
		//交集
		vector<int> v3;
		v3.resize(min(v1.size(), v2.size()) + 5);
		vector<int>::iterator ret = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
		for_each(v3.begin(), ret, MyPrint<int>(ret - v3.begin()));
	}

	{
		//并集
		vector<int> v3;
		v3.resize(v1.size() + v2.size());
		vector<int>::iterator ret = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
		for_each(v3.begin(), ret, MyPrint<int>(ret - v3.begin()));
	}

	{
		//差集
		vector<int> v3;
		v3.resize(v1.size());
		//v1差v2
		vector<int>::iterator ret = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
		for_each(v3.begin(), ret, MyPrint<int>(ret - v3.begin()));
		//v2差v1
		ret = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v3.begin());
		for_each(v3.begin(), ret, MyPrint<int>(ret - v3.begin()));
	}
}

void test5()
{
	//"初始化"容器
	vector<int> v1;
	vector<int> v2;

	Random<vector<int>>()(v1, 10);
	Random<vector<int>>()(v2, 10);

	cout << "fill前:" << endl;
	for_each(v1.begin(), v1.end(), MyPrint<int>(v1.size()));
	cout << "fill后:" << endl;
	fill(v1.begin(), v1.end(), 100);
	for_each(v1.begin(), v1.end(), MyPrint<int>(v1.size()));

	cout << "fill_n前:" << endl;
	for_each(v2.begin(), v2.end(), MyPrint<int>(v2.size()));
	cout << "fill_n后:" << endl;
	fill_n(v2.begin(), v2.size() / 2, 666);
	for_each(v2.begin(), v2.end(), MyPrint<int>(v2.size()));
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();

	system("pause");
	return 0;
}