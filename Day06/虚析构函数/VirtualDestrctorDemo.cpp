#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class String
{
public:
	String(const char *str) : name(strncpy(new char[strlen(str) + 1], str, strlen(str) + 1)) 
	{
		if(name != nullptr)
			cout << "String()" << endl;
	}
	~String()
	{
		if (name != nullptr)
		{
			cout << "~String()" << endl;
			delete[] name;
		}
	}
	const char* getName()
	{
		return name;
	}
private:
	const char * const name;
};
class MyA
{
public:
	MyA(const char *str)
	{
		cout << "MyA()" << endl;
		name = new String(str);
	}
	virtual ~MyA()
	{
		if (name != nullptr)
		{
			cout << "~MyA():" << name->getName() << endl;
			delete this->name;
		}
	}
protected:
	String *name;
};

class MyB : public MyA
{
public:
	MyB(const char *str) : MyA(str)
	{
		cout << "MyB()" << endl;
		name = new String(str);
	}
	virtual ~MyB()
	{
		if (name != nullptr)
		{
			cout << "~MyB():" << name->getName() << endl;
			delete this->name;
		}
	}
protected:
	String *name;
};

/*
class MyC : public MyA, public MyB
{
public:
	MyC(const char *str) : MyA(str), MyB(str)
	{
		cout << "MyC()" << endl;
		name = new String(str);
	}
	virtual ~MyC()
	{
		if (name != nullptr)
		{
			cout << "~MyC():" << name->getName() << endl;
			delete this->name;
		}
	}
protected:

	String *name;
};
*/

class MyD : public MyB
{
public:
	MyD(const char *str) : MyB(str)
	{
		cout << "MyD()" << endl;
		name = new String(str);
	}
	virtual ~MyD()
	{
		if (name != nullptr)
		{
			cout << "~MyD():" << name->getName() << endl;
			delete this->name;
		}
	}
protected:
	String *name;
};

void TestFunc(MyA *a)
{
	delete a;
}
void TestFun()
{
	//TestFunc(new MyA("AAAAA"));
	//TestFunc(new MyB("BBBBB"));
	//TestFunc(new MyC("CCCCC"));
	TestFunc(new MyD("DDDDD"));
}
int main(int argv, char *argc[])
{
	TestFun();

	system("pause");
	return 0;
}