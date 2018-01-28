#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main7()
{
	stack<string> sInputStr;
	string buf;
	while (getline(cin, buf))
	{
		if (buf.empty()) continue;
		buf.push_back(' ');
		string::iterator index = buf.begin(), beg = index + buf.find(' '), End = buf.end();
		sInputStr.emplace(string(index, beg));
		index = beg++ + 1;
		while (beg != End)
		{
			if (*beg == ' ' || beg == End - 1)
			{
				sInputStr.emplace(string(index, beg) + ' ');
				index = beg + 1;
			}
			++beg;
		}
		while (!sInputStr.empty())
		{
			cout << sInputStr.top();
			sInputStr.pop();
		}
		cout << endl;
	}
	return 0;
}

int main()
{
	vector<string> sInputStr;
	string buf;
	while (getline(cin, buf))
	{
		buf.push_back(' ');
		string::iterator index = buf.begin(), beg = index + buf.find(' '), End = buf.end();
		sInputStr.emplace_back(string(index, beg));
		index = beg++ + 1;
		while (beg != End)
		{
			if (*beg == ' ' || beg == End - 1)
			{
				sInputStr.emplace_back(string(index, beg) + ' ');
				index = beg + 1;
			}
			++beg;
		}
		reverse(sInputStr.begin(), sInputStr.end());
		for(string &s : sInputStr)
		{
			cout << s;
		}
		cout << endl;
	}
	return 0;
}