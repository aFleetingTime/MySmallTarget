#include <iostream>
#include <vector>
#include <iterator>
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

template<class T>
void show(vector<T> &v)
{
	for (vector<int>::iterator beg = v.begin(), End = v.end(); beg != End; ++beg)
	{
		cout << *beg << ' ';
	}
	cout << endl;
}

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

void vector_test_1()
{
	vector<int> v1 = { 10,20,30,40,50,60,70,80,90 };
	cout << "before assign:" << endl;
	show(v1);
	int a[5] = { 1, 2, 3, 4, 5 };
	v1.assign(begin(a), end(a));
	cout << "after assign:" << endl;
	show(v1);
}

void vector_test_2()
{
	vector<int> v1;
	for (int i = 0; i < 1000; i++)
	{
		v1.push_back(i);
	}
	cout << "size:" << v1.size() << endl;
	cout << "capacity:" << v1.capacity() << endl;
	//cout << v1.at(1000) << endl;	//error
}

void vector_test_3()
{
	vector<int> v1 = { 10,20,30,40,50,60,70,80,90 };
	v1.erase(v1.begin() + 5, v1.end());
	show(v1);
}

int main()
{
	//for_each_test();
	//for_each_test_2();
	//for_each_test_3();
	//vector_test_1();
	//vector_test_2();
	vector_test_3();

	system("pause");
	return 0;
}