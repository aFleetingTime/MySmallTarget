#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;


class Test
{
public:
	Test(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

void queue_store_stack()
{
	queue<stack<Test>> queSta;
	string name;
	for (int i = 0; i < 5; i++)
	{
		stack<Test> temp;
		for (int j = 0; j < 5; j++)
		{
			name.push_back('A' + j);
			temp.push(Test(name, j + 1));
			name.pop_back();
		}
		queSta.push(temp);
	}
	while (!queSta.empty())
	{
		while (!queSta.front().empty())
		{
			cout << "Name:" << queSta.front().top().name << " Age:" << queSta.front().top().age << endl;
			queSta.front().pop();
		}
		queSta.pop();
		cout << "------------" << endl;
	}
}

void test()
{
	for (int i = 0; i < 5; i++)
	{
		Test a("1", i);
	}
	system("pause");
}

int main()
{
	//queue_store_stack();
	//test();
	queue<int> a;

	system("pause");
	return 0;
}