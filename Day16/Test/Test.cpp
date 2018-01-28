#include <iostream>
#include <vector>

using namespace std;

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

int main()
{
	vector<int> v(10);

	cout << v.end() - v.begin() << endl;

	system("pause");
	return 0;
}