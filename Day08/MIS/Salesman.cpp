#include "Salesman.h"



Salesman::Salesman(std::string name, unsigned int LV, unsigned int wage, unsigned int week) : Staff(name, LV, wage, week)
{
}


Salesman::~Salesman()
{
	name = "";
	LV = 1;
	wage = 0;
	week = 0;
}

void Salesman::setWeek(unsigned int week)
{
	this->week = week;
}

int Salesman::getNumber()
{
	return number;
}

void Salesman::showWage()
{
	std::cout << "����Ա���:" << number << std::endl;
	std::cout << "����:" << name << std::endl;
	std::cout << "LVΪ:" << LV << std::endl;
	std::cout << "��нΪ:" << wage << std::endl;
	std::cout << "���Ϊ:" << wage + (wage * (double(week) / 1000)) << std::endl;
}
