#pragma once
#include "Employee.h"

class Manager : public Employee
{
public:
	Manager(std::string name, unsigned level);
	~Manager();
	virtual void showInfo();
	virtual double getPay();
	void setLevel(unsigned level);
private:
	const double wage;
	double levelCommission;
	const double levelProportion;
};

