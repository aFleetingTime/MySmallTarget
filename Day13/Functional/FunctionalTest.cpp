#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

void functional_test_1()
{
	cout << plus<int>()(10, 20) << endl;
}
void print(int a, int b)
{
	cout << "a:" << a << " b:" << b << endl;
}
class Test1 : public binary_function<int,int,void>
{
public:
	void operator()(int value, int num) const
	{
		cout << value - num << ' ';
	}
};
class Test2 : public binary_function<int, int, bool>
{
public:
	bool operator()(int value, int num) const
	{
		return value < num;
	}
};
class Test22 : public binary_function<int, int, bool>	//binary_function ���ڱ���Ԫ�����������̳�
{
public:
	bool operator()(int value, int num) const
	{
		return value == num;
	}
};
class Test222 : public unary_function<int, bool>	//unary_function ���ڱ�һԪ�����������̳�
{
public:
	bool operator()(int value) const
	{
		return value >= 50;
	}
};

vector<int> ivec = { 20, 10, 30, 50, 40 };

//��������	bind1st��bind2nd
void adapter_test_1()
{
	//��100�󶨵�Test1����operator()(int value, int num)������value�β�
	for_each(ivec.begin(), ivec.end(), bind1st(Test1(), 100));	cout << endl;
	//��100�󶨵�Test1����operator()(int value, int num)������num�β�
	for_each(ivec.begin(), ivec.end(), bind2nd(Test1(), 100));	cout << endl;
}

//ȡ�������� not1��not2
void adapter_test_2()
{
	sort(ivec.begin(), ivec.end(), Test2());
	for_each(ivec.begin(), ivec.end(), bind2nd(Test1(), 0));	cout << endl;
	//��Test2�����bool operator()(int value, int num)�����ķ��ؽ��ȡ��
	sort(ivec.begin(), ivec.end(), not2(Test2()));
	for_each(ivec.begin(), ivec.end(), bind2nd(Test1(), 0));	cout << endl;

	vector<int>::iterator ret = find_if(ivec.begin(), ivec.end(), bind2nd(Test22(), 10));
	cout << "find_if return:" << *ret << endl;

	//һԪ��������ȡ��
	ret = find_if(ivec.begin(), ivec.end(), Test222());
	cout << "t2 find_if return:" << *ret << endl;	//50
	//��Test222�����bool operator()(int value)�����ķ��ؽ��ȡ��
	ret = find_if(ivec.begin(), ivec.end(), not1(Test222()));
	cout << "t2 find_if not1 return:" << *ret << endl;	//40
}

//α���������� ptr_fun
void adapter_test_3()
{
	for_each(ivec.begin(), ivec.end(), bind2nd(ptr_fun(print), 100));
}

int main()
{
	//functional_test_1();
	//adapter_test_1();
	//adapter_test_2();
	adapter_test_3();

	system("pause");
	return 0;
}