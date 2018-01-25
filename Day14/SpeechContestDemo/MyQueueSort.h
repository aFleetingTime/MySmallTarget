#pragma once
#include "SpeechPlayer.h"

class MyQueueSort : binary_function<SpeechPlayer, SpeechPlayer, bool>
{
public:
	MyQueueSort();
	~MyQueueSort();
	bool operator()(SpeechPlayer &p1, SpeechPlayer &p2) const;
};

