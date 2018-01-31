#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <unordered_map>


using namespace std;

pair<int, int> findNum(vector<int> array)	//O(n)
{
	clock_t start = clock(), end = 0;
	map<int, int> nmap;
	for (int &num : array)
		++nmap[num];
	pair<int, int> max;
	for (map<int, int>::iterator beg = nmap.begin(), End = nmap.end(); beg != End; ++beg)
	{
		if (max.second < beg->second)
			max = *beg;
	}
	end = clock();
	cout << "用时:" << end - start << "ms" << endl;
	return max;
}

pair<int, int> findNum_2(vector<int> array)
{
	clock_t start = clock(), end = 0;
	set<int> mset;
	for (int &i : array)
		mset.insert(i);
	vector<int>::iterator abeg = array.begin(), aend = array.end();
	ptrdiff_t max_count = 0, temp = 0;
	int max_num = 0;
	for (const int &i : mset)
	{
		temp = count(abeg, aend, i);
		if (temp > max_count)
		{
			max_count = temp;
			max_num = i;
		}
	}
	end = clock();
	cout << "用时:" << end - start << "ms" << endl;
	return make_pair(max_num, max_count);
}

pair<int, int> findNum_3(vector<int> array)
{
	clock_t start = clock(), end = 0;
	vector<int> count;
	count.resize(10000);
	
	for (int &i : array)
	{
		++count[i];
	}
	int max_count = 0, max_num = 0;
	for (int i = 0; i < 10000; ++i)
	{
		if (count[i] > max_count)
		{
			max_count = count[i];
			max_num = i;
		}
	}
	end = clock();
	cout << "用时:" << end - start << "ms" << endl;
	return make_pair(max_num, max_count);
}

void findNum_4(vector<int> array)
{
	clock_t start = clock(), end = 0;
	map<int, int> imap;
	for (int &i : array)
	{
		pair<map<int, int>::iterator, bool> p = imap.insert(make_pair(i, 1));
		if (!p.second)
			++p.first->second;
	}
	int max_count = 0, max_num = 0;
	for (pair<const int, int> p : imap)
	{
		if (max_count < p.second)
		{
			max_count = p.second;
			max_num = p.first;
		}
	}
	end = clock();
	cout << "用时:" << end - start << "ms" << endl;
	cout << "number:" << max_num << endl;
	cout << "count:" << max_count << endl;
}

struct Hash
{
	size_t operator()(const int &num) const
	{
		return hash<int>()(num);
	}
};

struct IntCompare
{
	bool operator()(const int &a, const int &b) const
	{
		return a == b;
	}
};

void findNum_5(vector<int> array)
{
	clock_t start = clock(), end = 0;
	unordered_map<int, int> imap;
	//unordered_map<int, int, Hash, IntCompare> imap;
	for (int &i : array)
		++imap[i];
	int max_count = 0, max_num = 0;
	for (pair<const int, int> p : imap)
	{
		if (max_count < p.second)
		{
			max_count = p.second;
			max_num = p.first;
		}
	}
	end = clock();
	cout << "用时:" << end - start << "ms" << endl;
	cout << "number:" << max_num << endl;
	cout << "count:" << max_count << endl;
}

int main()
{
	srand((unsigned)time(nullptr));
	vector<int> ivec;
	ivec.reserve(10000000);
	for (int i = 0; i < 10000000; ++i)
		ivec.push_back(rand() % 1000 + 1);

	pair<int, int> p;

	cout << "findNum5:" << endl;
	findNum_5(ivec);
	cout << endl;

	cout << "findNum4:" << endl;
	findNum_4(ivec);
	cout << endl;

	cout << "findNum3:" << endl;
	p = findNum_3(ivec);
	cout << "number:" << p.first << endl;
	cout << "count:" << p.second << endl << endl;

	cout << "findNum1:" << endl;
	p = findNum(ivec);
	cout << "number:" << p.first << endl;
	cout << "count:" << p.second << endl << endl;


	system("pause");
	return 0;
}