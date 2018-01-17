#include <iostream>

using namespace std;

class Test1
{
public:
	Test1(int a)
	{
		this->a = a;
	}
	virtual void print()
	{
		cout << "Test1::a = " << a << endl;
	}
private:
	int a;
};
class Test2 : public Test1
{
public:
	Test2(int a, int b) : Test1(a)
	{
		this->b = b;
	}
	void print()	//一旦基类有一个函数修饰为virtual，那么无论派生类是否重写基类virtual函数，该派生类都会存在vptr指针（指向虚函数表）。
	{				//派生类复写的基类的virtual函数不添加virtual修饰符也会被virtual修饰
		Test1::print();
		cout << "Test2::b = " << b << endl;
	}
private:
	int b;
};
class Test3 : public Test2
{
public:
	Test3(int a, int b, int c) : Test2(a, b)
	{
		this->c = c;
	}
	void print()
	{
		Test2::print();
		cout << "Test3::c = " << c << endl;
	}
private:
	int c;
};
int main()
{
	Test1 t1(1);
	Test2 t2(2, 3);
	Test3 t3(3, 4, 5);

	cout << "sizeof(t1) = " << sizeof(t1) << endl;
	cout << "sizeof(t2) = " << sizeof(t2) << endl;
	cout << "sizeof(t3) = " << sizeof(t3) << endl;
	cout << "---------------" << endl;

	Test1 *tp1 = &t3;
	tp1->print();

	delete t4;
	system("pause");
	return 0;
}

