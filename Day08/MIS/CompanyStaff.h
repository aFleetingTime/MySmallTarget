#pragma once
#include <string>
#include "Company.h"

class CompanyStaff
{
public:
	CompanyStaff(std::string, unsigned int, unsigned int);
	virtual ~CompanyStaff() = 0;
	virtual void showWage() = 0;
	virtual int getNumber() = 0;

protected:
	std::string name;
	unsigned int LV;
	unsigned int wage;
	const unsigned int number;
};

