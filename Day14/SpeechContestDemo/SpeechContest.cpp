#include "SpeechContest.h"



SpeechContest::SpeechContest()
{
	srand((unsigned)time(nullptr));
	mGroupNum = GROUP_NUM;
	mJudgesNum = JUDGES_NUM;
}

SpeechContest::SpeechContest(unsigned groupNum, unsigned t, unsigned judgesNum)
{
	srand((unsigned)time(nullptr));
	mGroupNum = groupNum;
	mJudgesNum = judgesNum;
	if(t >= groupNum)
		mT = groupNum / 2;
	else
		mT = t;
}


SpeechContest::~SpeechContest()
{
}


void SpeechContest::contestantEntry(vector<SpeechPlayer> &player)	//选手入场
{
	mPlayerList.resize(player.size());
	copy(player.begin(), player.end(), mPlayerList.begin());
	cout << "选手们已入场!" << endl << "--------------------------" << endl;
}
void SpeechContest::play()			//开始比赛
{
	unsigned group = 0;
	multimap<int, SpeechPlayer> mapPlayer = grouping(group);
	vector<SpeechPlayer> player;
	priority_queue<SpeechPlayer, vector<SpeechPlayer>, MyQueueSort> temp;
	
	for (unsigned i = 1; i <= group; ++i)
	{
		pair<MyMapIterator, MyMapIterator> p = mapPlayer.equal_range(i);
		JudgeGrading(p, mJudgesNum, i);
		
		priority_queue<SpeechPlayer, vector<SpeechPlayer>, MyQueueSort> priQueue;
		while (p.first != p.second)
		{
			priQueue.push(p.first->second);
			++(p.first);
		}
		temp = priQueue;
		cout << "第" << group << "组选手名单:" << endl;
		while (!temp.empty())
		{
			temp.top().showInfo();
			temp.pop();
		}
		cout << "--------------------------" << endl;
		//淘汰掉一个小组一半选手
		if (mPlayerList.size() > mT)
		{
			for (int y = 0; y != mT; ++y)
				priQueue.pop();
		}
		else
		{
			for (int y = 0; y != mT / 2; ++y)
				priQueue.pop();
		}
		
		//将入围选手添加进临时容器
		while (!priQueue.empty())
		{
			player.push_back(priQueue.top());
			priQueue.pop();
		}
	}
	mPlayerList.assign(player.begin(), player.end());
	if (mPlayerList.size() <= 3)
		showPlayerRank();
	else
		showPlayer();
}
multimap<int, SpeechPlayer> SpeechContest::grouping(unsigned &g)		//分组
{
	size_t head = mPlayerList.size();
	unsigned groupNum = 0;
	if(head % mGroupNum == 0)
		groupNum = head / mGroupNum;
	else
		groupNum = head / mGroupNum + 1;
	random_shuffle(mPlayerList.begin(), mPlayerList.end());
	multimap<int, SpeechPlayer> pMap;
	vector<SpeechPlayer>::iterator beg = mPlayerList.begin(), End = mPlayerList.end();
	for (unsigned i = 0, group = 1; i != groupNum; ++i, ++group)
	{
		for (int y = 0; y != mGroupNum && beg != End; ++y, ++beg)
		{
			pMap.insert(make_pair(group, *beg));
		}
	}
	g = groupNum;
	return pMap;
}
void SpeechContest::JudgeGrading(pair<MyMapIterator, MyMapIterator> p, int judgetNum, unsigned group)	//评委打分
{
	deque<unsigned> score;
	while (p.first != p.second)
	{
		for (int i = 0; i != judgetNum; ++i)
			score.push_back(rand() % 91 + 10);
		score.pop_back();
		score.pop_front();
		p.first->second.mScore = accumulate(score.begin(), score.end(), 0) / score.size();
		score.clear();
		//p.first->second.showInfo(true);
		++(p.first);
	}
}

void SpeechContest::showPlayerRank()
{
	vector<SpeechPlayer>::iterator beg = mPlayerList.begin(), End = mPlayerList.end();
	sort(beg, End);
	string rankS("冠军亚军季军");
	string::iterator sbeg = rankS.begin(), send = rankS.begin();
	while (beg != End)
	{
		cout << string(sbeg, send += 4) << ": ";
		beg->showInfo();
		sbeg += 4;
		++beg;
	}
	cout << "--------------------------" << endl;

#if 0
	priority_queue<SpeechPlayer, vector<SpeechPlayer>, MyQueueSort> pQueue;
	map<string, SpeechPlayer> rank;


	string rankS("冠军亚军季军");
	string::iterator sbeg = rankS.begin(), send = rankS.begin();
	while (!pQueue.empty())
	{
		rank.insert(make_pair(string(sbeg, send += 4), pQueue.top()));
		pQueue.pop();
		sbeg += 4;
	}
	for (map<string, SpeechPlayer>::reverse_iterator beg = rank.rbegin(), End = rank.rend(); beg != End; ++beg)
	{
		cout << beg->first << ":";
		beg->second.showInfo(true);
	}
#endif
}

void SpeechContest::showPlayer()
{
	cout << "入围选手名单:" << endl;
	//vector<SpeechPlayer>::reverse_iterator beg = mPlayerList.rbegin(), End = mPlayerList.rend();
	vector<SpeechPlayer>::iterator beg = mPlayerList.begin(), End = mPlayerList.end();
	sort(beg, End, MyNumSort());
	while (beg != End)
	{
		beg->showInfo();
		++beg;
	}
	cout << "--------------------------" << endl;
}
