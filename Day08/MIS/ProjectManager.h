#pragma once
#include "Director.h"
#include <iostream>

class ProjectManager : public Director
{
public:
	ProjectManager(std::string, unsigned LV, unsigned wage);
	virtual void showWage();
	virtual ~ProjectManager();
	virtual int getNumber();
};

