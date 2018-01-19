#include "CompanyStaff.h"



CompanyStaff::CompanyStaff(std::string name, unsigned int LV, unsigned int wage) : number(Company::number++)
{
	this->name = name;
	this->LV = LV;
	this->wage = wage;
}
CompanyStaff::~CompanyStaff()
{

}