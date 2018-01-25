#pragma once
#include "SpeechPlayer.h"

class MyNumSort
{
public:
	MyNumSort();
	~MyNumSort();
	bool operator()(SpeechPlayer &, SpeechPlayer &);
};

