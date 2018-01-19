#include "Director.h"



Director::Director(std::string name, unsigned int LV, unsigned int wage, double commission) : CompanyStaff(name, LV, wage)
{
	this->commission = commission;
}
Director::~Director()
{

}