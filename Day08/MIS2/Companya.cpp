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
		std::cout << "�����Ա�������Ϊ:" << emp->getID() << std::endl << "------------" << std::endl;
	}
	else
		std::cout << "���ʧ��:Ա��ʵ��Ϊ��!" << std::endl << "------------" << std::endl;
}

void Companya::disEmployee()
{
	unsigned int id = cinID();
	for (auto temp : employee)
	{
		if (temp != nullptr && temp->getID() == id)
		{
			delete temp;
			std::cout << "�ѽ��" << id << "�������Ӧ��Ա��" << std::endl << "------------" << std::endl;
			return;
		}
	}
	std::cout << "û����" << id << "��Ŷ�Ӧ��Ա��" << std::endl << "------------" << std::endl;
}

void Companya::setEmployee()
{
	unsigned int id = cinID();
	for (auto temp : employee)
	{
		if (temp != nullptr && temp->getID() == id)
		{
			unsigned int it;
			std::cout << "������ȼ�:" << std::endl;
			while ((std::cout << ">>", std::cin >> it) && (it > 10 || it < 1))
				std::cout << "�ȼ����ڹ涨��Χ��,����������" << std::endl << "------------" << std::endl;
			temp->setLevel(it);
			return;
		}
	}
	std::cout << "û����" << id << "��Ŷ�Ӧ��Ա��" << std::endl << "------------" << std::endl;
}

Employee * Companya::recruitEmployee()
{
	showMenu();
	Employee *temp = nullptr;
	std::string name;
	int enter = 0;
	unsigned level, salesVolume;
	Start:
	std::cout << "������Ա��ְλ:" << std::endl << ">>";
	std::cin >> enter;
	std::cout << "------------" << std::endl;
	switch (enter)
	{
	case 1:
		std::cout << "��������:�������ȼ�:" << std::endl << ">>";
		std::cin >> name >> level;
		temp = new Manager(name, level);
		break;
	case 2:
		std::cout << "��������:�������ȼ������۶�:" << std::endl << ">>";
		std::cin >> name >> level >> salesVolume;
		temp = new Salesmanr(name, level, salesVolume);
		break;
	case 3:
		std::cout << "��������:�������ȼ������۶�:" << std::endl << ">>";
		std::cin >> name >> level >> salesVolume;
		temp = new SalesManager(name, level, salesVolume);
		break;
	case 4:
		std::cout << "��������:�������ȼ�������ʱ��:" << std::endl << ">>";
		std::cin >> name >> level >> salesVolume;
		temp = new Technician(name, level, salesVolume);
		break;
	default:
		std::cout << "û�и�ѡ��,����������!" << std::endl << "------------" << std::endl;
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
	std::cout << "û����" << id << "��Ŷ�Ӧ��Ա��" << std::endl << "------------" << std::endl;
}

unsigned int Companya::cinID()
{
	std::cout << "������Ա�����:" << std::endl << ">>";
	int enter = 0;
	std::cin >> enter;
	return enter;
}

void Companya::showMenu()
{
	std::cout << "------------" << std::endl;
	std::cout << "-1.����"<< std::endl;
	std::cout << "-2.����Ա"<< std::endl;
	std::cout << "-3.���۾���" << std::endl;
	std::cout << "-4.������Ա" << std::endl;
	std::cout << "------------" << std::endl;
}
