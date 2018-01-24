#pragma once
#include <iostream>
#include <string>

class Map_Employee
{
public:
	Map_Employee(std::string name, unsigned age, unsigned phone, unsigned salary);
	~Map_Employee();
	void getInfo(std::string &name, unsigned &age, unsigned &phone, unsigned &salary);
	bool operator<(Map_Employee m);
private:
	std::string name;
	unsigned age;
	unsigned phone;
	unsigned salary;
};

