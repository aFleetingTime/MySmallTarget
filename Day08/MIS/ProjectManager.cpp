#include "ProjectManager.h"



ProjectManager::ProjectManager(std::string name, unsigned LV, unsigned wage) : Director(name, LV, wage, 0)
{
		
}

void ProjectManager::showWage()
{
	std::cout << "项目经理编号:" << number << std::endl;
	std::cout << "姓名:" << name << std::endl;
	std::cout << "LV为:" << LV << std::endl;
	std::cout << "月薪为:" << wage << std::endl;
}

int ProjectManager::getNumber()
{
	return number;
}

ProjectManager::~ProjectManager()
{
	name = "";
	LV = 1;
	wage = 0;
}
