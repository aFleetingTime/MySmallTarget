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

//ÿ������
#define GROUP_NUM 6
//��ί����
#define JUDGES_NUM 10

using MyMapIterator = multimap<int, SpeechPlayer>::iterator;

class SpeechContest
{
public:
	SpeechContest();
	SpeechContest(unsigned, unsigned, unsigned);
	~SpeechContest();
	void contestantEntry(vector<SpeechPlayer>&);				//ѡ���볡
	void play();												//��ʼ����

private:
	multimap<int, SpeechPlayer> grouping(unsigned&);			//����
	void JudgeGrading(pair<MyMapIterator, MyMapIterator>, int, unsigned);	//��ί���
	void showPlayerRank();										//��ʾѡ���������ھ����Ǿ���������
	void showPlayer();											//��ʾ��Χѡ��
	vector<SpeechPlayer> mPlayerList;

private:
	unsigned mGroupNum;
	unsigned mJudgesNum;
	unsigned mT;
};

