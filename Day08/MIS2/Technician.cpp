#include "Technician.h"



Technician::Technician(std::string name, unsigned level, unsigned hours) : Employee(name, level), unitPrice(100)
{
	this->workHours = hours;
	this->wage = this->workHours * unitPrice * (double(level) / 10 + 1);
}


Technician::~Technician()
{
	this->workHours = 0;
	this->wage = 0;
}

void Technician::showInfo()
{
	std::cout << "ְλ:����" << std::endl;
	std::cout << "����:" << name << std::endl;
	std::cout << "���:" << id << std::endl;
	std::cout << "�ȼ�:" << level << std::endl;
	std::cout << "��н:" << wage << std::endl;
}

double Technician::getPay()
{
	return wage;
}

void Technician::setLevel(unsigned level)
{
	this->level = level;
	this->wage = this->workHours * unitPrice * (double(this->level) / 10 + 1);
}
