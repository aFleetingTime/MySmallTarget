#include "Manager.h"



Manager::Manager(std::string name, unsigned level) : Employee(name, level), levelProportion(0.03), wage(8000)
{
	this->levelCommission = level * levelProportion;
}


Manager::~Manager()
{
	levelCommission = 0;
}

void Manager::showInfo()
{
	std::cout << "职位:经理" << std::endl;
	std::cout << "姓名:" << name << std::endl;
	std::cout << "编号:" << id << std::endl;
	std::cout << "等级:" << level << std::endl;
	std::cout << "月薪:" << wage + (wage * levelCommission) << std::endl;
}

double Manager::getPay()
{
	return wage + (wage * levelCommission);
}

void Manager::setLevel(unsigned level)
{
	this->level = level;
	this->levelCommission = level * levelProportion;
}
