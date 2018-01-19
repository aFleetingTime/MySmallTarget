#include "Company.h"



Company::Company()
{
}


Company::~Company()
{
	for (auto temp : dir)
	{
		if (temp != nullptr)
			delete temp;
	}
}
void Company::showMenu()
{
	std::cout << "----------" << std::endl;
	std::cout << "1.���Ա��" << std::endl;
	std::cout << "2.��ѯԱ��" << std::endl;
	std::cout << "----------" << std::endl;
}
void Company::addEmployees(CompanyStaff *staff)
{
	if (staff != nullptr)
	{
		dir.push_back(staff);
	}
	else
	{
		std::cout << "���ʧ��:Ա��ʵ��Ϊ��" << std::endl;
	}
}

bool Company::getEmployeesInfo(unsigned num)
{
	for (auto temp : dir)
	{
		if (temp->getNumber() == num)
		{
			temp->showWage();
			return true;
		}
	}
	return false;
}

unsigned int Company::number = 1000;