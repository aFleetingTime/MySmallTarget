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
	std::cout << "ְλ:���۾���" << std::endl;
	std::cout << "����:" << name << std::endl;
	std::cout << "���:" << id << std::endl;
	std::cout << "�ȼ�:" << level << std::endl;
	std::cout << "��н:" << wage << std::endl;
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
