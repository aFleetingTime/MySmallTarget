#pragma once
#include <vector>
#include "Employee.h"
#include "Salesmanr.h"
#include "Manager.h"
#include "SalesManager.h"
#include "Technician.h"

class Companya
{
public:
	Companya();
	~Companya();
	void addEmployee(Employee *);
	void disEmployee();
	void setEmployee();
	Employee * recruitEmployee();
	void showEmployee();
	unsigned int cinID();

private:
	void showMenu();
	std::vector<Employee *> employee;
	static unsigned employeeNum;
};

