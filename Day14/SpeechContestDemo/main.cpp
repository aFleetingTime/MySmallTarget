#include <iostream>
#include <string>
#include "SpeechContest.h"
#include "SpeechPlayer.h"

using namespace std;

int main()
{
	vector<SpeechPlayer> player = SpeechPlayer::registration(48);
	SpeechContest speech(12, 6, 10);
	speech.contestantEntry(player);
	for (int i = 1; i <= 4; i++)
	{
		system("pause");
		cout << "--------------------------" << endl;
		if(i != 4)
			cout << "µÚ" << i << "ÂÖ" << endl << "--------------------------" << endl;
		else
			cout << "¾öÈü" << endl << "--------------------------" << endl;
		speech.play();
	}

	system("pause");
	return 0;
}