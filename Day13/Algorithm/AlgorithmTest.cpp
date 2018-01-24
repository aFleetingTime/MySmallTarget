#include <iostream>
#include <algorithm>
#include <functional>
#include <list>

using namespace std;

class Test
{
public:
	Test()
	{
		mId = 0;
		mAge = 0;
	}
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
class MyCopy
{
public:
	Test operator()(const Test &t) const
	{
		return t;
	}
};
class MyPrint
{
public:
	void operator()(const Test &t) const
	{
		cout << "ID:" << t.mId << " Age:" << t.mAge << endl;
	}
};

list<Test> gList = { Test(1, 2), Test(3, 1), Test(4, 5), Test(4, 8), Test(6, 7), Test(10, 7), Test(7, 7), Test(7, 7) };

void adjacent_find_test()
{
	//ʹ�ö�������==�߼�����������������������ֵ�Ԫ��
	list<Test>::iterator ret = adjacent_find(gList.begin(), gList.end());
	if (ret != gList.end()) cout << "ID:" << ret->mId << " Age:" << ret->mAge << endl;
	else cout << "û���ҵ��������ظ����ֵ�Ԫ��" << endl;
	//ʹ���Զ���Ĺ��򣨻ص������������󣩽��в����������������ֵ�Ԫ��
	ret = adjacent_find(gList.begin(), gList.end(), MyCompare());
	if (ret != gList.end()) cout << "ID:" << ret->mId << " Age:" << ret->mAge << endl;
	else cout << "û���ҵ��������ظ����ֵ�Ԫ��" << endl;
}

void find_if_test()
{
	list<Test>::iterator ret = find_if(gList.begin(), gList.end(), bind2nd(MyCompare(), Test(10, 7)));
	if (ret != gList.end()) cout << "ID:" << ret->mId << " Age:" << ret->mAge << endl;
	else cout << "û���ҵ��������ظ����ֵ�Ԫ��" << endl;
}

void count_if_test()
{
	//ͳ��������ָ��Ԫ�صĸ���
	ptrdiff_t cou = count(gList.begin(), gList.end(), Test(7, 7));
	cout << "Test(7,7)��" << cou << "��" << endl;

	//���Զ���Ĺ��򣨻ص�������������ͳ��������ָ��Ԫ�صĸ���
	cou = count_if(gList.begin(), gList.end(), bind2nd(MyCompare(), Test(3, 1)));
	cout << "Test(3,1)��" << cou << "��" << endl;
}

void transform_test()
{
	list<Test> test;
	test.resize(gList.size());
	transform(gList.rbegin(), gList.rend(), test.begin(), MyCopy());
	for_each(test.begin(), test.end(), MyPrint());
}

int main()
{
	//adjacent_find_test();
	//find_if_test();
	//count_if_test();
	transform_test();

	system("pause");
	return 0;
}