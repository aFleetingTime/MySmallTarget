#include <iostream>
#include <string>

template<class T>
class TemplatePerson;
template<class T>
void print(TemplatePerson<T> &per);

template<class T>
class TemplatePerson
{
public:
	TemplatePerson(std::string name, int age, T info)
	{
		this->name = name;
		this->age = age;
		this->info = info;
	}
	void show()
	{
		std::cout << "Name:" << name << std::endl;
		std::cout << "Age:" << age << std::endl;
		std::cout << "Info:" << info << std::endl;
	}
	friend void print<T>(TemplatePerson<T> &per);
private:
	std::string name;
	int age;
	T info;
};

template<class T>
void print(TemplatePerson<T> &per)
{
	std::cout << "Name:" << per.name << std::endl;
	std::cout << "Age:" << per.age << std::endl;
	std::cout << "Info:" << per.info << std::endl;
}