#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>
#include <set>
#include <iomanip>
#include <deque>
#include <ctime>
#include <numeric>
#include <queue>
#include <stack>
#include "SpeechPlayer.h"
#include "SpeechMyPrint.h"
#include "MyQueueSort.h"
#include "MyNumSort.h"
#include "MyMapSort.h"

using namespace std;

//每组人数
#define GROUP_NUM 6
//评委数量
#define JUDGES_NUM 10

using MyMapIterator = multimap<int, SpeechPlayer>::iterator;

class SpeechContest
{
public:
	SpeechContest();
	SpeechContest(unsigned, unsigned, unsigned);
	~SpeechContest();
	void contestantEntry(vector<SpeechPlayer>&);				//选手入场
	void play();												//开始比赛

private:
	multimap<int, SpeechPlayer> grouping(unsigned&);			//分组
	void JudgeGrading(pair<MyMapIterator, MyMapIterator>, int, unsigned);	//评委打分
	void showPlayerRank();										//显示选手排名（冠军、亚军、季军）
	void showPlayer();											//显示入围选手
	vector<SpeechPlayer> mPlayerList;

private:
	unsigned mGroupNum;
	unsigned mJudgesNum;
	unsigned mT;
};

