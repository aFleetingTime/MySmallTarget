#include <iostream>
#include <algorithm>
#include <functional>
#include <list>

using namespace std;

class Test
{
public:
	Test(int id, int age)
	{
		mId = id;
		mAge = age;
	}
	void show()
	{
		cout << "ID:" << mId << " Age:" << mAge << endl;
	}
	bool operator==(const Test &t) const
	{
		return mId == t.mId && mAge == t.mAge;
	}
	int mId;
	int mAge;
};
class MyCompare : public binary_function<Test, Test, bool>
{
public:
	bool operator()(const Test &a, const Test &b) const
	{
		return a.mId == b.mId && a.mAge == b.mAge;
	}
};

list<Test> gList = { Test(1, 2), Test(3, 1), Test(4, 5), Test(4, 8), Test(6, 7), Test(10, 7), Test(7, 7), Test(7, 7) };

void adjacent_find_test()
{
	//使用对象重载==逻辑运算符查找相邻且连续出现的元素
	list<Test>::iterator ret = adjacent_find(gList.begin(), gList.end());
	if (ret != gList.end()) cout << "ID:" << ret->mId << " Age:" << ret->mAge << endl;
	else cout << "没有找到相邻且重复出现的元素" << endl;
	//使用自定义的规则（回调函数或函数对象）进行查找相邻且连续出现的元素
	ret = adjacent_find(gList.begin(), gList.end(), MyCompare());
	if (ret != gList.end()) cout << "ID:" << ret->mId << " Age:" << ret->mAge << endl;
	else cout << "没有找到相邻且重复出现的元素" << endl;
}

void find_if_test()
{
	list<Test>::iterator ret = find_if(gList.begin(), gList.end(), bind2nd(MyCompare(), Test(10, 7)));
	if (ret != gList.end()) cout << "ID:" << ret->mId << " Age:" << ret->mAge << endl;
	else cout << "没有找到相邻且重复出现的元素" << endl;
}

void count_if_test()
{
	//统计容器中指定元素的个数
	ptrdiff_t cou = count(gList.begin(), gList.end(), Test(7, 7));
	cout << "Test(7,7)有" << cou << "个" << endl;

	//按自定义的规则（回调函数或函数对象）统计容器中指定元素的个数
	cou = count_if(gList.begin(), gList.end(), bind2nd(MyCompare(), Test(3, 1)));
	cout << "Test(3,1)有" << cou << "个" << endl;
}

int main()
{
	//adjacent_find_test();
	//find_if_test();
	count_if_test();

	system("pause");
	return 0;
}