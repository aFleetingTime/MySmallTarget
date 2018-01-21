#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include <iterator>


using namespace std;

class Test
{
public:
	Test(string name)
	{
		this->name = name;
		cout << name << ":Test()" << endl;
	}
	~Test()
	{
		cout << name << ":~Test()" << endl;
	}
	string name;
};

void fun() throw (exception)
{
	Test t1("111");
	Test t2("222");
	throw new exception;
}

int main(int argv, char *argc[])
{
	try
	{
		Test t3("333");
		Test t4("444");
		fun();
		Test t5("555");
	}
	catch (exception *e)
	{
		cout << e->what() << endl;
		delete e;
	}
	cout << "over" << endl;
	
	system("pause");
	return 0;
}