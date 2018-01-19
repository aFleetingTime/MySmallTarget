#pragma once
#include <string>
#include <iostream>
#include "Staff.h"

class Salesman : public Staff
{
public:
	Salesman(std::string name, unsigned int LV, unsigned int wage, unsigned int week);
	~Salesman();
	virtual void setWeek(unsigned int);
	virtual int getNumber();
	virtual void showWage();
};

