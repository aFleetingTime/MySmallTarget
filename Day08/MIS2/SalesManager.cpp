#include "SalesManager.h"



SalesManager::SalesManager(std::string name, unsigned level, double salesVolume) : Salesmanr(name, level, salesVolume), salary(5000)
{
	this->salesVolume = salesVolume;
	this->levelCommission = commission * level;
	this->wage = salary  + (this->salesVolume * this->levelCommission);
}


SalesManager::~SalesManager()
{
	wage = 0;
	levelCommission = 0;
	salesVolume = 0;
}

void SalesManager::showInfo()
{
	std::cout << "职位:销售经理" << std::endl;
	std::cout << "姓名:" << name << std::endl;
	std::cout << "编号:" << id << std::endl;
	std::cout << "等级:" << level << std::endl;
	std::cout << "月薪:" << wage << std::endl;
}

double SalesManager::getPay()
{
	return wage;
}

void SalesManager::setLevel(unsigned level)
{
	this->level = level;
	this->levelCommission = level * commission;
	this->wage = salary + (this->salesVolume * this->levelCommission);;
}
