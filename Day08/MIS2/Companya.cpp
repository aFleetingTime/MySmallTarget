#include "Companya.h"

unsigned Companya::employeeNum = 0;

Companya::Companya()
{
}

Companya::~Companya()
{
	for (auto temp : employee)
	{
		if (temp != nullptr)
			delete temp;
	}
}

void Companya::addEmployee(Employee *emp)
{
	if (emp != nullptr)
	{
		employee.push_back(emp);
		std::cout << "已添加员工，编号为:" << emp->getID() << std::endl << "------------" << std::endl;
	}
	else
		std::cout << "添加失败:员工实例为空!" << std::endl << "------------" << std::endl;
}

void Companya::disEmployee()
{
	unsigned int id = cinID();
	for (auto temp : employee)
	{
		if (temp != nullptr && temp->getID() == id)
		{
			delete temp;
			std::cout << "已解雇" << id << "编号所对应的员工" << std::endl << "------------" << std::endl;
			return;
		}
	}
	std::cout << "没有与" << id << "编号对应的员工" << std::endl << "------------" << std::endl;
}

void Companya::setEmployee()
{
	unsigned int id = cinID();
	for (auto temp : employee)
	{
		if (temp != nullptr && temp->getID() == id)
		{
			unsigned int it;
			std::cout << "请输入等级:" << std::endl;
			while ((std::cout << ">>", std::cin >> it) && (it > 10 || it < 1))
				std::cout << "等级不在规定范围内,请重新输入" << std::endl << "------------" << std::endl;
			temp->setLevel(it);
			return;
		}
	}
	std::cout << "没有与" << id << "编号对应的员工" << std::endl << "------------" << std::endl;
}

Employee * Companya::recruitEmployee()
{
	showMenu();
	Employee *temp = nullptr;
	std::string name;
	int enter = 0;
	unsigned level, salesVolume;
	Start:
	std::cout << "请输入员工职位:" << std::endl << ">>";
	std::cin >> enter;
	std::cout << "------------" << std::endl;
	switch (enter)
	{
	case 1:
		std::cout << "依次输入:姓名、等级:" << std::endl << ">>";
		std::cin >> name >> level;
		temp = new Manager(name, level);
		break;
	case 2:
		std::cout << "依次输入:姓名、等级、销售额:" << std::endl << ">>";
		std::cin >> name >> level >> salesVolume;
		temp = new Salesmanr(name, level, salesVolume);
		break;
	case 3:
		std::cout << "依次输入:姓名、等级、销售额:" << std::endl << ">>";
		std::cin >> name >> level >> salesVolume;
		temp = new SalesManager(name, level, salesVolume);
		break;
	case 4:
		std::cout << "依次输入:姓名、等级、工作时长:" << std::endl << ">>";
		std::cin >> name >> level >> salesVolume;
		temp = new Technician(name, level, salesVolume);
		break;
	default:
		std::cout << "没有该选项,请重新输入!" << std::endl << "------------" << std::endl;
		goto Start;
	};
	return temp;
}

void Companya::showEmployee()
{
	unsigned int id = cinID();
	for (auto temp : employee)
	{
		if (temp != nullptr && temp->getID() == id)
		{
			temp->showInfo();
			return;
		}
	}
	std::cout << "没有与" << id << "编号对应的员工" << std::endl << "------------" << std::endl;
}

unsigned int Companya::cinID()
{
	std::cout << "请输入员工编号:" << std::endl << ">>";
	int enter = 0;
	std::cin >> enter;
	return enter;
}

void Companya::showMenu()
{
	std::cout << "------------" << std::endl;
	std::cout << "-1.经理"<< std::endl;
	std::cout << "-2.推销员"<< std::endl;
	std::cout << "-3.销售经理" << std::endl;
	std::cout << "-4.技术人员" << std::endl;
	std::cout << "------------" << std::endl;
}
