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
			cout << "----------" << endl << "1.��Ŀ����" << endl << "2.����Ա" << endl << "----------" << endl;
			cin >> enter;
			switch (enter)
			{
			case 1:
				cout << "----------" << endl << "�������ȼ�����н:" << endl;
				cin >> name >> LV >> wage;
				temp = new ProjectManager(name, LV, wage);
				break;
			case 2:
				cout << "�������ȼ�����н������ʱ��:" << endl;
				cin >> name >> LV >> wage >> commis;
				temp = new Salesman(name, LV, wage, commis);
				break;
			default:
				cout << "û�и�ѡ������������!" << endl;
				goto Staff;
			}
			com.addEmployees(temp);
			break;
		case 2:
			cout << "----------" << endl << "Ա�����:" << endl;
			unsigned int num;
			cin >> num;
			if (!com.getEmployeesInfo(num))
			{
				cout << "----------" << endl << "û���ҵ��ñ�Ŷ�Ӧ��Ա��" << endl;
			}
			break;
		}
	}

	system("pause");
	return 0;
}