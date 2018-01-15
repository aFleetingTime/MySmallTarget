#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class SubClass
{
public:
	SubClass()
	{
		this->name = "SubClass";
	}
	void sleep()
	{
		cout << name << " sleep" << endl;
	}
protected:
	string name;
private:
};

class DerivedClassA : virtual public SubClass
{
public:
	DerivedClassA()
	{
		id = 'A';
	}
	void showID()
	{
		sleep();
		cout << id << endl;
	}
protected:
	int id;
private:
};

class DerivedClassB : virtual public SubClass
{
public:
	DerivedClassB()
	{
		id = 'B';
	}
	void showID()
	{
		sleep();
		cout << id << endl;
	}
protected:
	int id;
private:
};

class Sub : public DerivedClassA, public DerivedClassB
{
public:
	Sub(int num) : DerivedClassA(), DerivedClassB()
	{
		this->subNum = num;
	}
	void showSub()
	{
		DerivedClassA::showID();
		DerivedClassB::showID();
		cout << subNum << endl;
	}
protected:
private:
	int subNum;
};

int main(int argv, char *argc[])
{
	Sub sub(10);
	sub.showSub();

	system("pause");
	return 0;
}