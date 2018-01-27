#include <iostream>
#include <map>
#include <functional>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int getIntLen(int num)
{
	int count = 0;
	while (num)
	{
		num /= 10;
		++count;
	}
	return count;
}

void add(int &num, int len)
{
	for (int i = 0; i < len; ++i)
	{
		num *= 10;
	}
}

string link(int num, int *arr)
{
	int temp = 0, len = 0;
	multimap<int, int, greater<int>> imap;
	for (int i = 0; i < num; ++i)
	{
		temp = arr[i];
		len = getIntLen(temp);
		switch (len)
		{
		case 2:
			temp /= 10;
			break;
		case 3:
			temp /= 100;
			break;
		case 4:
			temp /= 1000;
			break;
		}
		imap.insert(make_pair(temp, arr[i]));
	}
	int tempA = 0, tempB = 0;
	string str;
	for (multimap<int, int, greater<int>>::iterator beg = imap.begin(), End = imap.end(); beg != End; ++beg)
	{
		multimap<int, int, greater<int>>::iterator tempBeg = beg;
		++tempBeg;
		tempA = getIntLen(beg->second);
		if (tempBeg == End || beg->first > tempBeg->first)
		{
			str += to_string(beg->second);
		}
		else
		{
			tempB = getIntLen(tempBeg->second);
			int t1 = pow(10, tempA - 1), t2 = pow(10, tempB - 1);
			int s = max(tempA, tempB);
			for (int i = 0; i < s; ++i, t1 /= 10, t2 /= 10)
			{
				if (t2 == 0)
					break;
				if (t1 == 0 || (beg->second / t1 < tempBeg->second / t2))
				{
					str += to_string(beg->second);
					swap(tempBeg->second, beg->second);
					goto Back;
				}
			}
			str += to_string(beg->second);
		Back:
			0;
		}
	}
	return str;
}
int main1()
{
	int num = 0;
	int arr[1024];
	vector<int> v;
	while (cin >> num)
	{
		v.clear();
		int temp;
		for (int i = 0; i < num; ++i)
		{
			cin >> arr[i];
			//v.push_back(temp);
		}
		cout << link(num, arr);
	}

	system("pause");
	return 0;
}