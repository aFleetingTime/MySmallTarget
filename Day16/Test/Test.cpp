#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Compare
{
public:
	Compare(int num) : mNum(num) {}
	bool operator()(vector<int> v1, vector<int> v2) const
	{
		if (binary_search(v1.begin(), v1.end(), mNum)) 
			return true;
		return v1[0] > mNum ? false : true;
	}
	int mNum;
};

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		for (vector<vector<int>>::iterator rEnd = array.begin() - 1, End = array.end(), mid = (rEnd+1) + array.size() / 2; mid != End && mid != rEnd; (*mid)[0] > target ? End = mid,mid = rEnd + ((End - rEnd + 1)/2) : rEnd = mid, mid = rEnd + ((End - rEnd) / 2))
		{
			for (int &i : *mid)
			{
				if (i == target)
					return true;
			}
		}
		return false;
	}
};
	bool com(vector<int> a, vector<int> c)
	{
		return true;
	}
int main()
{
	vector<vector<int>> v = {
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
	};

	//cout << (v.end() >= v.begin()) << endl;
	//auto End = v[0].begin();
	//if (find(v[1].begin(), v[1].end(), 10) != End)
	cout << binary_search(v.begin(), v.end(), *v.rbegin(),Compare(16));
	system("pause");
	return 0;
}