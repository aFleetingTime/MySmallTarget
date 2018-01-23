#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Test
{
public:
	Test(const string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

void stack_store_object()
{
	stack<Test> testStack;
	string s("ABCDEFGH");
	for (int i = 0; i < 5; ++i)
	{
		s.push_back('A' + i);
		testStack.push(Test(s, i + 1));
		s.pop_back();
	}
	while (!testStack.empty())
	{
		cout << "Name:" << testStack.top().name << " Age:" << testStack.top().age << endl;
		testStack.pop();
	}
}

void stack_store_objectptr()
{
	stack<Test*> testStack;
	string s;
	for (int i = 0; i < 5; ++i)
	{
		s.push_back('A' + i);
		testStack.push(new Test(s, i + 1));
		s.pop_back();
	}
	while (!testStack.empty())
	{
		cout << "Name:" << testStack.top()->name << " Age:" << testStack.top()->age << endl;
		delete testStack.top();
		testStack.pop();
	}
}

int main()
{
	//stack_store_object();
	stack_store_objectptr();

	system("pause");
	return 0;
}