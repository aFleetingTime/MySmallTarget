#include "Employee.h"

int Employee::num = 1000;

Employee::Employee(std::string name, unsigned level)
{
	this->name = name;
	this->level = level;
	this->id = num++;
}


Employee::~Employee()
{
	name = "";
	id = 0;
	level = 0;
}

int Employee::getID()
{
	return this->id;
}
