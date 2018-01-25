#pragma once
#include <iostream>
#include <iomanip>
#include <functional>
#include "SpeechPlayer.h"

using namespace std;

class SpeechMyPrint : public binary_function<pair<const int, SpeechPlayer>, int, void>
{
public:
	void operator()(pair<string, SpeechPlayer> &palyer) const;
	void operator()(pair<const int, SpeechPlayer> &palyer) const;
	SpeechMyPrint();
	~SpeechMyPrint();
};

