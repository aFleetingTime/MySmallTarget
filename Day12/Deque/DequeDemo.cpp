#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <ctime>

using namespace std;

class Player
{
public:
	Player(string name, unsigned int score)
	{
		this->name.assign(name);
		this->score = score;
	}
	unsigned int& getScore()
	{
		return score;
	}
	string& getName()
	{
		return name;
	}
	static bool compare(Player &p1, Player &p2);
private:
	string name;
	unsigned int score;
};
bool Player::compare(Player &p1, Player &p2)
{
	return p1.score > p2.score;
}

void print(Player &p)
{
	cout << p.getName() << ':' << p.getScore() << endl;
}
void createPlayer(vector<Player> &vPlayer, int num)
{
	vPlayer.clear();
	char n[26] = { 'A','B','C','D','E','F' };
	string s("选手");
	for (int i = 0; i < num; ++i)
	{
		vPlayer.push_back(Player(s + n[i], 0));
	}
}
void scoring(vector<Player> &vPlayer, int num)
{
	deque<unsigned int> score;
	srand(static_cast<unsigned int>(time(nullptr)));
	for (vector<Player>::iterator beg = vPlayer.begin(), End = vPlayer.end(); beg != End; ++beg)
	{
		for (int i = 0; i < num; ++i)
		{
			score.push_back(rand() % 101);
		}
		sort(score.begin(), score.end());
		score.pop_front();
		score.pop_back();
		unsigned int score_sum = 0;
		for (deque<unsigned int>::iterator beg = score.begin(), End = score.end(); beg != End; ++beg)
		{
			score_sum += *beg;
		}
		(*beg).getScore() = score_sum / score.size();
		score.clear();
	}
	for_each(vPlayer.begin(), vPlayer.end(), print);
}
void ranks(vector<Player> &vPlayer, int num)
{
	//vector<Player>::iterator max;
	//for (vector<Player>::iterator beg = vPlayer.begin(), End = vPlayer.end() - 1; beg != End; ++beg)
	//{
	//	max = beg;
	//	for (vector<Player>::iterator begj = beg + 1, End = vPlayer.end(); begj != End; ++begj)
	//	{
	//		if ((*begj).getScore() > (*max).getScore())
	//		{
	//			max = begj;
	//		}
	//	}
	//	if (max != beg)
	//	{
	//		unsigned int temp = (*max).getScore();
	//		(*max).getScore() = (*beg).getScore();
	//		(*beg).getScore() = temp;
	//	}
	//}
	sort(vPlayer.begin(), vPlayer.end(), Player::compare);
	for (int i = 0; i < 3; ++i)
	{
		cout << "第" << i + 1 << "名:" << vPlayer.at(i).getName() << " 分数:" << vPlayer.at(i).getScore() << endl;
	}
	//for_each(vPlayer.begin(), vPlayer.end(), print);
}

int main()
{
	//vector<Player> player;
	//createPlayer(player, 5);
	//scoring(player, 10);
	//ranks(player, 5);
	deque<int> d;
	d.push_front(1);
	d.push_front(2);
	cout << d.front() << endl;
	d[5];
	system("pause");
	return 0;
}