#include <iostream>
#include <string>

using namespace std;

template<class T> class Person;
template<class T> void printPerson(Person<T> &per);
template<class T> ostream& operator<<(ostream & out, Person<T>& per);

template<class T>
class Person
{
public:
	Person(string name, T age, T id)
	{
		this->mName = name;
		this->mAge = age;
		this->mId = id;
	}
	void showInfo()
	{
		cout << "Name:" << mName << endl;
		cout << "Age:" << mAge << endl;
		cout << "Id:" << mId << endl;
	}
	friend void printPerson<T>(Person<T> &per);
	friend ostream& operator<<<T>(ostream &out, Person<T> &per);

private:
	string mName;
	T mAge;
	T mId;
};

template<class T>
ostream & operator<<(ostream & out, Person<T>& per)
{
	out << "Name:" << per.mName << endl;
	out << "Age:" << per.mAge << endl;
	out << "Id:" << per.mId;
	return out;
}

template<class T>
void printPerson(Person<T> &per)
{
	cout << "Name:" << per.mName << endl;
	cout << "Age:" << per.mAge << endl;
	cout << "Id:" << per.mId << endl;
}


int main(void)
{
	Person<int> person("test", 20, 11);
	cout << person << endl;
	printPerson(person);
	person.showInfo();

	system("pause");
	return 0;
}
