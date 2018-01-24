#include "Map_Employee.h"



Map_Employee::Map_Employee(std::string name, unsigned age, unsigned phone, unsigned salary)
{
	this->name = name;
	this->age = age;
	this->phone = phone;
	this->salary = salary;
}


Map_Employee::~Map_Employee()
{
}

void Map_Employee::getInfo(std::string &name, unsigned &age, unsigned &phone, unsigned &salary)
{
	name = this->name;
	age = this->age;
	phone = this->phone;
	salary = this->salary;
}

bool Map_Employee::operator<(Map_Employee m)
{
	return this->age > m.age;
}
