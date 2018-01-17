#pragma once
#include <string>
#include "MainBoard.h"

using namespace std;

//class IntelCPU : public CPU
//{
//public:
//	IntelCPU(string model);
//	void start();
//	void close();
//};
class IntelCPU : public CPU
{
public:
	IntelCPU(string model);
	void start();
	void close();
};

