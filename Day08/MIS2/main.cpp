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
		cout << "��ѡ����:" << endl << "------------" << endl << "1.���Ա��" << endl << "2.��ѯԱ��" << endl << "3.���Ա��" << endl << "4.�޸ĵȼ�" << endl << "5.�˳�ϵͳ" << endl << "------------" << endl;
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
			std::cout << "------------" << std::endl << "û�и�ѡ��,����������!" << std::endl;
			goto Start;
		}
	}
End:
	cout << "ϵͳ���˳�..." << endl;
	return 0;
}