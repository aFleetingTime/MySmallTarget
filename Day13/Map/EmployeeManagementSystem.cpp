#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include "Map_Employee.h"

using namespace std;
enum Reach
{
	SalesDepartment = 1, RDDepartment, FinancialSector, AllSectors
};

void showReachMenu()
{
	cout << "----------" << endl;
	cout << "1.���۲���" << endl;
	cout << "2.�з�����" << endl;
	cout << "3.������" << endl;
	cout << "4.���в���" << endl;
	cout << "----------" << endl;
}

istream& operator>>(istream &input, Reach &reach)
{
	int enter;
RET:
	showReachMenu();
	input >> enter;
	switch (enter)
	{
	case 1:
		reach = SalesDepartment;
		break;
	case 2:
		reach = RDDepartment;
		break;
	case 3:
		reach = FinancialSector;
		break;
	case 4:
		reach = AllSectors;
		break;
	default:
		goto RET;
	}
	return input;
}

class EmployeeSystem
{
public:
	void addEmployee(Map_Employee emp, Reach sectors)
	{
		emplo.insert(make_pair(sectors, emp));
	}
	void shwoReachEmployee(Reach sectors)
	{
		string name;
		unsigned age(0), phone(0), salary(0);
		
		if (sectors == AllSectors)
		{
			cout << "�ò�����" << emplo.size() << "��Ա��" << endl << "----------" << endl;
			multimap<Reach, Map_Employee>::iterator End = emplo.end();
			for (multimap<Reach, Map_Employee>::iterator beg = emplo.begin(); beg != End; ++beg)
			{
				beg->second.getInfo(name, age, phone, salary);
				cout << "����:" << name << endl << "����:" << age << endl << "�绰:" << phone << endl << "н��:" << salary << endl << "----------" << endl;
			}
		}
		else
		{
			cout << "�ò�����" << emplo.count(sectors) << "��Ա��" << endl << "----------" << endl;
			pair<multimap<Reach, Map_Employee>::iterator, multimap<Reach, Map_Employee>::iterator> p = emplo.equal_range(sectors);
			while (p.first != p.second)
			{
				p.first->second.getInfo(name, age, phone, salary);
				cout << "����:" << name << endl << "����:" << age << endl << "�绰:" << phone << endl << "н��:" << salary << endl << "----------" << endl;
				++p.first;
			}
			//for (multimap<Reach, Map_Employee>::iterator beg = emplo.find(sectors); beg != End && beg->first == sectors; ++beg)
			//{
			//	beg->second.getInfo(name, age, phone, salary);
			//	cout << "����:" << name << endl << "����:" << age << endl << "�绰:" << phone << endl << "н��:" << salary << endl << "----------" << endl;
			//}
		}
	}
	void showMenu()
	{
		cout << "----------" << endl;
		cout << "1.���Ա��" << endl;
		cout << "2.��ѯ����" << endl;
		cout << "3.�˳�ϵͳ" << endl;
		cout << "----------" << endl;
	}
private:
	multimap<Reach, Map_Employee> emplo;
};

int main()
{
	EmployeeSystem emp;
	string enter, name;
	stringstream ss;
	int ienter(0);
	unsigned age(0), phone(0), salary(0);
	Reach reach(AllSectors);
	while (true)
	{
		emp.showMenu();
		cin >> enter;
		ss.clear();
		ss << enter;
		ss >> ienter;
		switch (ienter)
		{
		case 1:
			cout << "��������:" << endl;
			cin >> reach;
			cout << "�����������������䡢�绰��н��:" << endl << ">>";
			cin >> name >> age >> phone >> salary;
			emp.addEmployee(Map_Employee(name,age,phone,salary), reach);
			cout << "��ӳɹ���" << endl;
			break;
		case 2:
			cout << "��ѯ����:" << endl;
			cin >> reach;
			emp.shwoReachEmployee(reach);
			break;
		case 3:
			goto END;
		}
	}
END:
	system("pause");
	return 0;
}