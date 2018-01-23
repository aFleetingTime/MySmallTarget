#include <iostream>
#include <string>

using namespace std;

void pair_test_1()
{
	pair<int, string> mPair = make_pair(1, "Ts");
	cout.setf(ios::right);
	cout.width(7);
	cout << "first:" << mPair.first << endl;
	cout.width(7);
	cout << "second:" << mPair.second << endl;
}
int main()
{
	pair_test_1();

	system("pause");
	return 0;
}