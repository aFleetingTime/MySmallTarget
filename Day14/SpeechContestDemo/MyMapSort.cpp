#include "MyMapSort.h"



MyMapSort::MyMapSort()
{
}


MyMapSort::~MyMapSort()
{
}

bool MyMapSort::operator()(pair<const int, SpeechPlayer> p1, pair<const int, SpeechPlayer> p2)
{
	return p1.second.mScore == p2.second.mScore ? p1.second.mNum > p2.second.mNum : p1.second.mScore > p2.second.mScore;
}
