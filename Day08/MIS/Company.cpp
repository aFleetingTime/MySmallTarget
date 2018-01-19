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
	std::cout << "1.添加员工" << std::endl;
	std::cout << "2.查询员工" << std::endl;
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
		std::cout << "添加失败:员工实例为空" << std::endl;
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