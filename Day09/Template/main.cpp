#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include <iterator>
#include "TemplatePerson.hpp"
#include "TemplateClassStatic.hpp"

using namespace std;


int main(int argv, char *argc[])
{

	TemplatePerson<string> person("test", 22, "abc");
	//person.show();
	print(person);

#if 0
	TemplateClassStatic<char> c;
	TemplateClassStatic<int> i;
	TemplateClassStatic<double> d;

	c.a = 'c';
	i.a = 666;
	d.a = 0.6;

	cout << c.a << endl;
	cout << i.a << endl;
	cout << d.a << endl;

	TemplateClassStatic<char>::a = 'b';
	TemplateClassStatic<int>::a = 777;
	TemplateClassStatic<double>::a = 0.7;

	cout << TemplateClassStatic<char>::a << endl;
	cout << TemplateClassStatic<int>::a << endl;
	cout << TemplateClassStatic<double>::a << endl;
#endif

	system("pause");
	return 0;
}