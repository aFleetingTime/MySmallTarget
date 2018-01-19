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
	std::cout << "ְλ:����" << std::endl;
	std::cout << "����:" << name << std::endl;
	std::cout << "���:" << id << std::endl;
	std::cout << "�ȼ�:" << level << std::endl;
	std::cout << "��н:" << wage + (wage * levelCommission) << std::endl;
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
