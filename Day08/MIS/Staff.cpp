#include "Staff.h"



Staff::Staff(std::string name, unsigned int LV, unsigned int wage, unsigned int week) : CompanyStaff(name, LV, wage)
{
	this->week = week;
}


Staff::~Staff()
{
}
