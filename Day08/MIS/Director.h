#pragma once
#include <string>
#include "Company.h"
#include "CompanyStaff.h"

class CompanyStaff;
class Director : public CompanyStaff
{
public:
	Director(std::string, unsigned int, unsigned int, double);
	virtual ~Director() = 0;
protected:
	double commission;
};

