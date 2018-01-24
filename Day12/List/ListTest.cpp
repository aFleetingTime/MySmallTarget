#include <list>
#include <algorithm>
#include <iostream>

using namespace std;
class Test
{
public:
	Test(int age)
	{
		this->age = age;
	}
	bool operator==(const Test &t) const
	{
		return this->age == t.age;
	}
	int age;
};
void test()
{
	list<int> l;
	for (int i = 0; i < 10; i++)
	{
		l.push_back(rand() % 200);
	}
	l.sort();
	//sort(l.begin(), l.end());
	for (auto t : l)
	{
		cout << t << " " << endl;
	}
}
void test_2()
{
	list<Test> l;
	l.push_back(Test(1));
	l.push_back(Test(2));
	l.emplace_back(6);
	l.remove(2);
	l.remove(1);
	cout << l.front().age << endl;
}

int main()
{
	//test();
	test_2();

	system("pause");
	return 0;
}