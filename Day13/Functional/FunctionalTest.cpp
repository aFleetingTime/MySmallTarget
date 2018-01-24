#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

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
class Test22 : public binary_function<int, int, bool>	//binary_function 用于被二元函数对象所继承
{
public:
	bool operator()(int value, int num) const
	{
		return value == num;
	}
};
class Test222 : public unary_function<int, bool>	//unary_function 用于被一元函数对象所继承
{
public:
	bool operator()(int value) const
	{
		return value >= 50;
	}
};
class Test4
{
public:
	Test4(string name, int age)
	{
		mName = name;
		mAge = age;
	}
	void showInfo()
	{
		cout << "Name:" << mName << " Age:" << mAge << endl;
	}
	void test(int a, int b)
	{

	}
private:
	string mName;
	int mAge;
};
void release(Test4 *pt)
{
	if (pt != nullptr)
		delete pt;
}

vector<int> ivec = { 20, 10, 30, 50, 40 };

//绑定适配器	bind1st和bind2nd
void adapter_test_1()
{
	//将100绑定到Test1对象operator()(int value, int num)函数的value形参
	for_each(ivec.begin(), ivec.end(), bind1st(Test1(), 100));	cout << endl;
	//将100绑定到Test1对象operator()(int value, int num)函数的num形参
	for_each(ivec.begin(), ivec.end(), bind2nd(Test1(), 100));	cout << endl;
}

//取反适配器 not1和not2
void adapter_test_2()
{
	sort(ivec.begin(), ivec.end(), Test2());
	for_each(ivec.begin(), ivec.end(), bind2nd(Test1(), 0));	cout << endl;
	//将Test2对象的bool operator()(int value, int num)函数的返回结果取反
	sort(ivec.begin(), ivec.end(), not2(Test2()));
	for_each(ivec.begin(), ivec.end(), bind2nd(Test1(), 0));	cout << endl;

	vector<int>::iterator ret = find_if(ivec.begin(), ivec.end(), bind2nd(Test22(), 10));
	cout << "find_if return:" << *ret << endl;

	//一元函数对象取反
	ret = find_if(ivec.begin(), ivec.end(), Test222());
	cout << "t2 find_if return:" << *ret << endl;	//50
	//将Test222对象的bool operator()(int value)函数的返回结果取反
	ret = find_if(ivec.begin(), ivec.end(), not1(Test222()));
	cout << "t2 find_if not1 return:" << *ret << endl;	//40
}

//伪函数适配器 ptr_fun
void adapter_test_3()
{
	//将print()全局函数适配为函数对象，再通过bind2nd绑定b形参的值为100
	for_each(ivec.begin(), ivec.end(), bind2nd(ptr_fun(print), 100));
}

//成员函数适配器 mem_fun和mem_fun_ref
void adapter_test_4()
{
	{
		vector<Test4> tvec = { Test4("T1", 10), Test4("T2", 20), Test4("T3", 30) };
		//tvec.emplace_back("T4", 40);
		//使用mem_fun_ref指定for_each每次遍历到的元素所进行调用的成员函数(mem_fun_ref仅限于元素为对象实例的容器，对象指针需要使用mem_fun)
		for_each(tvec.begin(), tvec.end(), mem_fun_ref(&Test4::showInfo));
	}
	cout << "---------" << endl;
	{
		vector<Test4*> tvec = { new Test4("T1", 10), new Test4("T2", 20), new Test4("T3", 30) };
		for_each(tvec.begin(), tvec.end(), mem_fun(&Test4::showInfo));
		for_each(tvec.begin(), tvec.end(), ptr_fun(release));
	}
}

void mem_function_test()
{
	Test4 t("1", 1);

	//mem_fun返回一个接收Test4 *类型的函数对象
	mem_fun_t<void, Test4> a = mem_fun(&Test4::showInfo);
	a(&t);

	//mem_fun_ref返回一个接收Test4 &类型的函数对象
	mem_fun_ref_t<void, Test4> b = mem_fun_ref(&Test4::showInfo);
	b(t);

	//成员函数指针的定义
	void(Test4::*fp)(int, int) = &Test4::test;

	//对象的成员函数通过函数指针调用
	(t.*fp)(11, 22);
}

int main()
{
	//functional_test_1();
	//adapter_test_1();
	//adapter_test_2();
	//adapter_test_3();
	//adapter_test_4();
	mem_function_test();

	system("pause");
	return 0;
}