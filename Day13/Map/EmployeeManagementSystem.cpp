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
	cout << "1.销售部门" << endl;
	cout << "2.研发部门" << endl;
	cout << "3.财务部门" << endl;
	cout << "4.所有部门" << endl;
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
			cout << "该部门有" << emplo.size() << "名员工" << endl << "----------" << endl;
			multimap<Reach, Map_Employee>::iterator End = emplo.end();
			for (multimap<Reach, Map_Employee>::iterator beg = emplo.begin(); beg != End; ++beg)
			{
				beg->second.getInfo(name, age, phone, salary);
				cout << "姓名:" << name << endl << "年龄:" << age << endl << "电话:" << phone << endl << "薪资:" << salary << endl << "----------" << endl;
			}
		}
		else
		{
			cout << "该部门有" << emplo.count(sectors) << "名员工" << endl << "----------" << endl;
			pair<multimap<Reach, Map_Employee>::iterator, multimap<Reach, Map_Employee>::iterator> p = emplo.equal_range(sectors);
			while (p.first != p.second)
			{
				p.first->second.getInfo(name, age, phone, salary);
				cout << "姓名:" << name << endl << "年龄:" << age << endl << "电话:" << phone << endl << "薪资:" << salary << endl << "----------" << endl;
				++p.first;
			}
			//for (multimap<Reach, Map_Employee>::iterator beg = emplo.find(sectors); beg != End && beg->first == sectors; ++beg)
			//{
			//	beg->second.getInfo(name, age, phone, salary);
			//	cout << "姓名:" << name << endl << "年龄:" << age << endl << "电话:" << phone << endl << "薪资:" << salary << endl << "----------" << endl;
			//}
		}
	}
	void showMenu()
	{
		cout << "----------" << endl;
		cout << "1.添加员工" << endl;
		cout << "2.查询部门" << endl;
		cout << "3.退出系统" << endl;
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
			cout << "所属部门:" << endl;
			cin >> reach;
			cout << "依次输入姓名、年龄、电话和薪资:" << endl << ">>";
			cin >> name >> age >> phone >> salary;
			emp.addEmployee(Map_Employee(name,age,phone,salary), reach);
			cout << "添加成功！" << endl;
			break;
		case 2:
			cout << "查询部门:" << endl;
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