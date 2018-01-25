#include "MyQueueSort.h"



MyQueueSort::MyQueueSort()
{
}


MyQueueSort::~MyQueueSort()
{
}


bool MyQueueSort::operator()(SpeechPlayer &p1, SpeechPlayer &p2) const
{
	//return p1.mScore == p2.mScore ? p1.mNum > p2.mNum : p1.mScore > p2.mScore;
	return p1.mScore == p2.mScore ? p1.mNum < p2.mNum : p1.mScore < p2.mScore;
}