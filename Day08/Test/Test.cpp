#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include <iterator>


using namespace std;


int main(int argv, char *argc[])
{
	vector<string> svec;
	string temp;

	while (getline(cin, temp) && !temp.empty())
		svec.push_back(temp);

	for (auto beg = svec.begin(); beg != svec.end() && !beg->empty(); ++beg)
	{
		for (char &temp : *beg)
			temp = toupper(temp);
		cout << *beg << endl;
	}

	system("pause");
	return 0;
}