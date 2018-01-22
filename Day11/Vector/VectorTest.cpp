#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person
{
public:
	Person(int age, int id)
	{
		this->age = age;
		this->id = id;
		cout << "Person()" << endl;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
	int age;
	int id;
};

void for_each_test()
{
	vector<char> cvec;
	//for (char t : "for_each_test")
	//{
	//	cvec.push_back(t);
	//}
	for (const char *beg = "for_each_test", *End = beg + strlen("for_each_test"); beg != End; beg++)
	{
		cvec.push_back(*beg);
	}
	cvec.pop_back();
	for_each(cvec.begin(), cvec.end(), [](char a) { cout << a << ' '; });
}

void for_each_test_2()
{
	vector<Person*> pvec;
	for (int i = 0; i < 3; i++)
	{
		pvec.push_back(new Person(i + 1, i + 5));
	}
	for_each(pvec.begin(), pvec.end(), [](Person *p)
	{ 
		static int si = 1;
		cout << "Person" << si++ << endl;
		cout << "age:" << p->age << endl;
		cout << "id:" << p->id << endl;
		delete p;
	});
}

void for_each_test_3()
{
	vector<vector<Person*>> pvec;
	for (int i = 0; i < 3; i++)
	{
		pvec.push_back(vector<Person*>());
		for (int j = 0; j < 3; j++)
		{
			pvec[i].push_back(new Person(i + j + 1,i + j + 5));
		}
	}

	for_each(pvec.begin(), pvec.end(), [](vector<Person*> &p)
	{
		static int si = 1;
		for_each(p.begin(), p.end(), [](Person *p1)
		{
			cout << "Person" << si++ << endl;
			cout << "age:" << p1->age << endl;
			cout << "id:" << p1->id << endl;
			delete p1;
		});
	});
}

int main()
{
	//for_each_test();
	//for_each_test_2();
	for_each_test_3();

	system("pause");
	return 0;
}