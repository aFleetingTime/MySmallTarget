#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	Person(string name)
	{
		this->name = name;
	}
	virtual void showName()
	{
		cout << "this man's name is " << name << endl;
	}
	static void show(Person *per);
protected:
	string name;
};
void Person::show(Person *per)
{
	per->showName();
}

class Worker : public Person
{
public:
	Worker(string name) : Person(name)
	{
		return;
	}
	void showName()
	{
		cout << "this worker's name is " << name << endl;
	}
};

class Student : public Person
{
public:
	Student(string name) : Person(name)
	{
		return;
	}
	void showName()
	{
		cout << "this student's name is " << name << endl;
	}
};

int main(int argv, char *argc[])
{
	Worker wor("zhang3");
	Student stu("zhao6");

	Person::show(&wor);
	Person::show(&stu);

	system("pause");
	return 0;
}