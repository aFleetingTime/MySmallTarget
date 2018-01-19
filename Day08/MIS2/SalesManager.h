#pragma once
#include "Manager.h"
#include "Salesmanr.h"

class SalesManager : public Salesmanr
{
public:
	SalesManager(std::string name, unsigned level, double salesVolume);
	~SalesManager();
	virtual void showInfo();
	virtual double getPay();
	void setLevel(unsigned level);
private:
	const double salary;
};

