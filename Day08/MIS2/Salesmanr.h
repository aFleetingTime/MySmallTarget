#pragma once
#include "Employee.h"
class Salesmanr : public Employee
{
public:
	Salesmanr(std::string name, unsigned level, double salesVolume);
	~Salesmanr();
	virtual void showInfo();
	virtual double getPay();
	void setLevel(unsigned level);

protected:
	double wage;
	const double commission;
	double levelCommission;
	double salesVolume;
};

