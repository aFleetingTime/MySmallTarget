#pragma once
#include "CompanyStaff.h"
#include <string>

class CompanyStaff;
class Staff : public CompanyStaff
{
public:
	Staff(std::string, unsigned int, unsigned int, unsigned int);
	virtual ~Staff() = 0;
	virtual void setWeek(unsigned int) = 0;
protected:
	unsigned int week;
};

