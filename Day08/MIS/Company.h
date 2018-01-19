#pragma once
#include <vector>
#include <iostream>
#include "CompanyStaff.h"

using namespace std;
class CompanyStaff;
class Company
{
public:
	Company();
	~Company();
	void showMenu();
	void addEmployees(CompanyStaff * staff);
	bool getEmployeesInfo(unsigned num);
	static unsigned int number;
private:
	vector<CompanyStaff(*)> dir;
};