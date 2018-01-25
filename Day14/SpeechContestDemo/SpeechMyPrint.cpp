#include "SpeechMyPrint.h"



SpeechMyPrint::SpeechMyPrint()
{
}


SpeechMyPrint::~SpeechMyPrint()
{
}
void SpeechMyPrint::operator()(pair<string, SpeechPlayer> &palyer) const
{
	cout << palyer.first << ":";
	palyer.second.showInfo();
}

void SpeechMyPrint::operator()(pair<const int, SpeechPlayer> &palyer) const
{
	palyer.second.showInfo();
}
