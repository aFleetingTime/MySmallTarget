#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include <iterator>
#include "TemplatePerson.hpp"

using namespace std;


int main(int argv, char *argc[])
{
	TemplatePerson<string> person("test", 22, "abc");
	person.show();
	
	system("pause");
	return 0;
}