#pragma once
#include "SpeechPlayer.h"

class MyMapSort
{
public:
	MyMapSort();
	~MyMapSort();
	bool operator()(pair<const int, SpeechPlayer> p1, pair<const int, SpeechPlayer> p2);
};

