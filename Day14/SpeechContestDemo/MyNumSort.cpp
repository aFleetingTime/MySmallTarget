#include "MyNumSort.h"



MyNumSort::MyNumSort()
{
}


MyNumSort::~MyNumSort()
{
}

bool MyNumSort::operator()(SpeechPlayer &p1, SpeechPlayer &p2)
{
	return p1.mNum < p2.mNum;
}
