#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <iterator>

using namespace std;

void priority_queue_test()
{
	{
		priority_queue<int, vector<int>, greater<int>> pqueue;
		for (int i = 0; i < 10; ++i)
			pqueue.push(rand() % 101 + 50);
		while (!pqueue.empty())
		{
			cout << pqueue.top() << " ";
			pqueue.pop();
		}
		cout << endl;
	}
	{
		priority_queue<int, vector<int>, less<int>> pqueue;
		for (int i = 0; i < 10; ++i)
			pqueue.push(rand() % 101 + 50);
		while (!pqueue.empty())
		{
			cout << pqueue.top() << " ";
			pqueue.pop();
		}
		cout << endl;
	}
}

template<class T>
class MyReplace
{
public:
	MyReplace(T num)
	{
		mReplaceNum = num;
	}
	bool operator()(T a)
	{
		return a == mReplaceNum;
	}
private:
	T mReplaceNum;
};

void test()
{
	vector<int> ivec{ 1, 2, 5, 6, 5, 6, 9, 10 ,11, 4, 5 };
	replace_if(ivec.begin(), ivec.end(), MyReplace<int>(5), 999);
	replace(ivec.begin(), ivec.end(), 4, 666);
	remove_if(ivec.begin(), ivec.end(), MyReplace<int>(9));
	transform(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " "), bind2nd(multiplies<int>(), 10));
}

int main()
{
	//priority_queue_test();
	test();

	system("pause");
	return 0;
}