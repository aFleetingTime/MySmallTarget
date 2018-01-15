#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	Person(int age, string name)
	{
		this->age = age;
		this->name = name;
	}
	void showInfo()
	{
		cout << "\tname:" << name << endl;
		cout << "\tage:" << age << endl;
	}
	static void print();
private:
	int age;
	string name;
};
void Person::print()
{
	cout << "\tPerson::print()" << endl;
}
class Student : protected Person
{
public:
	Student(int age, string name, int id, int score) : Person(age, name)
	{
		this->id = id;
		this->score = score;
	}
	void showInfo()
	{
		Person::showInfo();
		cout << "\tid:" << id << endl;
		cout << "\tscore:" << score << endl;
		print();
	}
private:
	int id;
	int score;
};

int main()
{
	Student stu(16, "zhang3", 111, 80);
	stu.showInfo();
	return 0;
}