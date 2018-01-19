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
	std::cout << "推销员编号:" << number << std::endl;
	std::cout << "姓名:" << name << std::endl;
	std::cout << "LV为:" << LV << std::endl;
	std::cout << "月薪为:" << wage << std::endl;
	std::cout << "提成为:" << wage + (wage * (double(week) / 1000)) << std::endl;
}
