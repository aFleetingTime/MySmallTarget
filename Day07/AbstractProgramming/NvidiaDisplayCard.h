#pragma once
#include "MainBoard.h"
class NvidiaDisplayCard : public DisplayCard
{
public:
	NvidiaDisplayCard(string);
	void start();
	void close();
};

