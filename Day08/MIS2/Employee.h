#pragma once
#include <iostream>
#include <string>

class Employee
{
public:
	Employee(std::string, unsigned);
	virtual ~Employee();
	virtual double getPay() = 0;
	virtual void showInfo() = 0;
	virtual void setLevel(unsigned) = 0;
	int getID();

protected:
	std::string name;
	unsigned id;
	unsigned level;

	static int num;
};

