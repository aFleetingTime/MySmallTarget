#include "SpeechPlayer.h"

SpeechPlayer::SpeechPlayer()
{
	mName = "";
	mAge = 0;
	mNum = 0;
	mScore = 0;
}

SpeechPlayer::SpeechPlayer(string name, unsigned age, int num, unsigned score)
{
	mName = name;
	mAge = age;
	mNum = num;
	mScore = score;
}


SpeechPlayer::~SpeechPlayer()
{
}

vector<SpeechPlayer> SpeechPlayer::registration(int num)
{
	srand((unsigned)time(nullptr));
	vector<SpeechPlayer> player;
	string name = "ѡ��";
	for (int i = 1; i <= num; ++i)
	{
		name.push_back('A' + i);
		player.push_back(SpeechPlayer(name, rand() % 10 + 10, i, 0));
		name.pop_back();
	}
	return player;
}

void SpeechPlayer::showInfo() const
{
	cout << "���:" << setw(2) << setfill('0') << mNum << " "
	   	 << "����:" << mName << " "
		 << "����:" << setw(2) << setfill('0') << mAge
		 << " �÷�:" << setw(3) << setfill('0') << mScore
	     << endl;
}

bool SpeechPlayer::operator<(const SpeechPlayer &p)
{
	return mScore == p.mScore ? mNum > p.mNum : mScore > p.mScore;
}
