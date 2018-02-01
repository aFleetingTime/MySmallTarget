#include <iostream>
#include <queue>
#include "MyQueue.h"

using namespace std;

int main()
{
	MyQueue<int> queue;

	for (int i = 0; i < 10; ++i)
		queue.push(i);

	cout << queue.back() << endl << endl;

	while (!queue.empty())
	{
		cout << queue.front() << endl;
		queue.pop();
	}

	

	system("pause");
	return 0;
}