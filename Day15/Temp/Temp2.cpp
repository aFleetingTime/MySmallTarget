#include <iostream>
#include <string>
#include <map>
#include <functional>

using namespace std;

int main()
{
	int count = 0;
	while (cin >> count)
	{
		multimap<int, string, greater<int>> mSort;
		string inputNum;
		for (int i = 0; i < count; ++i)
		{
			int temp;
			cin >> temp;
			inputNum = to_string(temp);
			mSort.insert(make_pair(inputNum.at(0) - '0', inputNum));
		}

		string outStr;
		for (int i = 9, count = 0; i > 0; --i)
		{
			if (count = mSort.count(i) == 0)
				continue;
			auto itPair = mSort.equal_range(i);
			if (count == 1)
			{
				outStr.append(itPair.first->second);
				continue;
			}
			while (itPair.first != itPair.second)
			{
				auto temp = itPair.first;
				string max;
				multimap<int, string, greater<int>>::iterator index;
				while (temp != itPair.second)
				{
					if (temp->second >= max)
					{
						max.assign(temp->second);
						index = temp;
					}
					++temp;
				}
				if(max.length() != 0)
					swap(index->second, itPair.first->second);
				outStr.append(max);
				++itPair.first;
			}
		}
		cout << outStr << endl;
	}
	return 0;
}