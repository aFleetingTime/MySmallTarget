#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
//#include "SpeechContest.h"

using namespace std;

class SpeechPlayer
{
public:
	SpeechPlayer();
	SpeechPlayer(string name, unsigned age, int num, unsigned score);
	~SpeechPlayer();
	static vector<SpeechPlayer> registration(int);
	void showInfo() const;
	bool operator<(const SpeechPlayer &);

public:
	string mName;
	unsigned mAge;
	int mNum;
	unsigned mScore;

private:
	
};

