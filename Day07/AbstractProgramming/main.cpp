#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <windows.h>
#include "Animal.h"
#include "Dog.h"
#include "MainBoard.h"
#include "IntelCPU.h"
#include "NvidiaDisplayCard.h"
#include "KingstonMemory.h"

using namespace std;

int main(int argv, char *argc[])
{
	MainBoard mainBoard(new IntelCPU("G4560"), new KingstonMemory("8G"), new NvidiaDisplayCard("GTX1050TI"));
	mainBoard.operation();
	Sleep(1000);
	mainBoard.closeComputer();

	//Animal *animal1 = new Dog;
	//animal1->voice();

	system("pause");
	return 0;
}