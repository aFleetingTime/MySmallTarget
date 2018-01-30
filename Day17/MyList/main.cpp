#include <string>
#include <iostream>
#include "MyList.h"
#include <list>

using namespace std;

template<class TYPE>
struct Compare
{
	bool operator()(TYPE &a, TYPE &b) const
	{
		return a < b;
	}
};

int main()
{
	MyLink<int> a;

	cout << "添加:" << endl;
	for(int i = 0; i < 10; ++i)
		a.push_back(i);
	a.print_list();
	cout << endl;

	cout << "插入:" << endl;
	a.insert(11, 666);
	a.print_list();
	cout << endl;
	
	cout << "删除:" << endl;
	for (int i = 0; i < 5; ++i)
		a.pop_back();
	a.print_list();
	cout << endl;
	
	cout << "首元素:" << endl;
	cout << a.front() << endl;
	cout << endl;

	cout << "尾元素:" << endl;
	cout << a.back() << endl;
	cout << endl;

	for (int i = 0; i < 10; ++i)
		a.push_front(rand() % 100 + 1);
	cout << "排序:" << endl;
	a.sort();
	a.print_list();
	cout << endl;

	cout << "自定义排序:" << endl;
	a.sort(Compare<int>());
	a.print_list();
	cout << endl;

	cout << "访问元素:" << endl;
	cout << a[15] << endl;
	cout << endl;

	system("pause");
	return 0;
}