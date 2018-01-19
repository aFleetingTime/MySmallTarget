#include "Salesmanr.h"



Salesmanr::Salesmanr(std::string name, unsigned level, double salesVolume) : Employee(name, level), commission(0.04)
{
	this->salesVolume = salesVolume;
	this->levelCommission = commission * level;
	this->wage = salesVolume * levelCommission;
}


Salesmanr::~Salesmanr()
{
	wage = 0;
	levelCommission = 0;
	salesVolume = 0;
}

void Salesmanr::showInfo()
{
	std::cout << "职位:推销员" << std::endl;
	std::cout << "姓名:" << name << std::endl;
	std::cout << "编号:" << id << std::endl;
	std::cout << "等级:" << level << std::endl;
	std::cout << "月薪:" << wage << std::endl;
}

double Salesmanr::getPay()
{
	return wage;
}

void Salesmanr::setLevel(unsigned level)
{
	this->level = level;
	this->levelCommission = level * commission;
	this->wage = salesVolume * levelCommission;
}