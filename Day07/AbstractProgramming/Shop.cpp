#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Place
{
public:
	virtual void produce() = 0;
protected:
	unsigned int business = 0;
};

class Person : public Place
{
public:
	Person(string name)
	{
		this->name = name;
	}
	void produce()
	{
		++business;
		cout << name << " business:" << business << endl;
	}
private:
	string name;
};

int main(int argv, char *argc[])
{
	Place *p = new Person("Aise");
	p->produce();
	delete p;

	system("pause");
	return 0;
}