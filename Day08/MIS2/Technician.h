#pragma once
#include "Employee.h"
class Technician :
	public Employee
{
public:
	Technician(std::string name, unsigned level, unsigned hours);
	~Technician();
	virtual void showInfo();
	virtual double getPay();
	void setLevel(unsigned level);

private:
	const double unitPrice;
	unsigned wage;
	unsigned workHours;
};

