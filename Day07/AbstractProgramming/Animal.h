#pragma once
#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
	virtual void voice() = 0;
	string bark;
};

