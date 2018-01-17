#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Animal.h"
#include "Dog.h"

using namespace std;

int main(int argv, char *argc[])
{
	Animal *animal1 = new Dog;
	animal1->voice();

	system("pause");
	return 0;
}