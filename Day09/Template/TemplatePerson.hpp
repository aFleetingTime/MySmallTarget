#include <iostream>
#include <string>

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
private:
	std::string name;
	int age;
	T info;
};