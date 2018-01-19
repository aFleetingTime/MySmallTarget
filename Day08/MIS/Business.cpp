#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include <iterator>
#include "Company.h"
#include "ProjectManager.h"
#include "Salesman.h"

using namespace std;


int main(int argv, char *argc[])
{
	unsigned int enter = 0;
	Company com;
	vector<CompanyStaff*> aa;

	while (true)
	{
		com.showMenu();
		cin >> enter;
		CompanyStaff *temp = nullptr;
		string name;
		unsigned int LV, wage, commis;

		switch (enter)
		{
		case 1:
			Staff:
			cout << "----------" << endl << "1.项目经理" << endl << "2.推销员" << endl << "----------" << endl;
			cin >> enter;
			switch (enter)
			{
			case 1:
				cout << "----------" << endl << "姓名、等级、月薪:" << endl;
				cin >> name >> LV >> wage;
				temp = new ProjectManager(name, LV, wage);
				break;
			case 2:
				cout << "姓名、等级、月薪、工作时间:" << endl;
				cin >> name >> LV >> wage >> commis;
				temp = new Salesman(name, LV, wage, commis);
				break;
			default:
				cout << "没有该选项请重新输入!" << endl;
				goto Staff;
			}
			com.addEmployees(temp);
			break;
		case 2:
			cout << "----------" << endl << "员工编号:" << endl;
			unsigned int num;
			cin >> num;
			if (!com.getEmployeesInfo(num))
			{
				cout << "----------" << endl << "没有找到该编号对应的员工" << endl;
			}
			break;
		}
	}

	system("pause");
	return 0;
}