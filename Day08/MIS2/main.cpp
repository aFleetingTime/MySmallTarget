#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include <iterator>
#include "Employee.h"
#include "Salesmanr.h"
#include "Manager.h"
#include "Companya.h"

using namespace std;


int main(int argv, char *argc[])
{
	Companya comp;
	unsigned enter = 0;
	while (true)
	{
		cout << "可选操作:" << endl << "------------" << endl << "1.添加员工" << endl << "2.查询员工" << endl << "3.解雇员工" << endl << "4.修改等级" << endl << "5.退出系统" << endl << "------------" << endl;
	Start:
		cout << ">>";
		cin >> enter;
		switch (enter)
		{
		case 1:
			comp.addEmployee(comp.recruitEmployee());
			break;
		case 2:
			comp.showEmployee();
			break;
		case 3:
			comp.disEmployee();
			break;
		case 4:
			comp.setEmployee();
			break;
		case 5:
			goto End;
		default:
			std::cout << "------------" << std::endl << "没有该选项,请重新输入!" << std::endl;
			goto Start;
		}
	}
End:
	cout << "系统已退出..." << endl;
	return 0;
}