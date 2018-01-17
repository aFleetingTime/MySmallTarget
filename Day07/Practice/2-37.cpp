#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main(int argv, char *argc[])
{
	int a = 3, b = 4;
	decltype(a) c = a;		//int c = a(3);
	decltype(a = b) d = a;	//int &d = a(4);
	//decltype不会实际计算表达式
	//a = 3, b = 4, c = 3, d = 3
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	//decltype和auto
	//共同点：decltype和auto都可以通过变量、或表达式结果的类型来决定自身类型，。
	//区别：decltype可以声明引用，而auto不可以。
	//	   如果decltype的表达式是const常量引用，decltype同样将声明一个常量引用。而auto在初始化时传入常量引用，auto所声明的引用将舍弃const

	system("pause");
	return 0;
}