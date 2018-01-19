#include "ProjectManager.h"



ProjectManager::ProjectManager(std::string name, unsigned LV, unsigned wage) : Director(name, LV, wage, 0)
{
		
}

void ProjectManager::showWage()
{
	std::cout << "��Ŀ������:" << number << std::endl;
	std::cout << "����:" << name << std::endl;
	std::cout << "LVΪ:" << LV << std::endl;
	std::cout << "��нΪ:" << wage << std::endl;
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
