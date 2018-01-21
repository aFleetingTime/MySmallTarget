#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include <iterator>


using namespace std;

class Test1 {};
class Test2 {};
class Test3 : public Test2 {};

void static_cast_test()	//用于转换内置类型、具有继承关系的类和类的指针、引用(不做类型安全检查)
{
	//static_cast能够转换基本数据类型（包括指针和引用）、具有继承关系的基类与派生类之间的转换（包括指针和引用，不能由基类向派生类转换）,而无法转换没有继承关系的类
	int i = 0;
	double d = static_cast<double>(i);

	char c = 65;
	short s = static_cast<short>(c);

	Test2 *t2p = nullptr;
	Test3 *t3p = static_cast<Test3*>(t2p);

	//Test2 t2;		不能从基类向派生类转换
	//Test3 t3 = static_cast<Test3>(t2);

	//Test1 *t1;	不能转换没有继承关系的类，包括指针和引用
	//Test2 *t2 = static_cast<Test2*>(t1);
}

void dynamic_cast_test() //用于转换具有继承关系的类的指针和引用（会做类型安全检查，转换基类指针时，无法像static_cast那样将基类指针转换为派生类指针）
{
	Test3 *t3 = nullptr;
	Test2 *t2 = t3;

	Test3 *t33 = nullptr;
	Test2 *t22 = dynamic_cast<Test2*>(t33);

	//Test3 t33;	只能转换指针或引用类型
	//Test2 t22 = dynamic_cast<Test2>(t33);

	//Test2 *t2 = nullptr;	不能从基类向派生类转换
	//Test3 *t3 = dynamic_cast<Test3*>(t2);

	//int *i = 0;	不能转换内置类型和内置复合类型
	//char *c = dynamic_cast<int*>(i);

	//Test2 t2;		不能从基类向派生类转换
	//Test3 t3 = dynamic_cast<Test3>(t2);
}

void const_cast_test() //用于获取添加或取消const后的指针、引用、对象类型指针
{
	int i = 0;
	const int &ai = i;
	const_cast<int&>(ai) = 100;
	cout << i << endl;

	const int &ai1 = i;
	int &cai = const_cast<int&>(ai1);
	cai = 1000;
	cout << i << endl;

	const int &a = 0;
	const_cast<int&>(a) = 10;
	cout << a << endl;

	//const int &cai1 = const_cast<const int &>(cai);
	//cai1 = 10000;
}

void reinterpret_cast_test() //强制类型转换，可以将指针(包括函数指针)或引用转换为任意类型
{
	Test1 *t1 = nullptr;
	Test2 *t2 = reinterpret_cast<Test2*>(t1);

	int *ip = nullptr;
	string *sp = reinterpret_cast<string*>(ip);

	int *i = 0;
	char *s = reinterpret_cast<char*>(i);

	int *&ai = i;
	string *&&as = reinterpret_cast<string*>(ai);

	string *****&&ass = reinterpret_cast<string*****>(ai);
}

int main(int argv, char *argc[])
{
	static_cast_test();
	dynamic_cast_test();
	const_cast_test();
	reinterpret_cast_test();

	system("pause");
	return 0;
}