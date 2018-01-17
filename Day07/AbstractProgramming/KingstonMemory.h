#pragma once
#include "MainBoard.h"
#include <iostream>

using namespace std;

class KingstonMemory : public Memory
{
public:
	KingstonMemory(string model);
	void start();
	void close();
};

