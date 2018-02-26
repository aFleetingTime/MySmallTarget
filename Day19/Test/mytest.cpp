#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <memory>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

class Test
{
public:
	Test()
	{
		t = new int();
	}
	int test()
	{
		void **v = nullptr;
	}
	~Test()
	{
		cout << "..." << *t << endl;
		delete t;
		system("pause");
	}

private:
	int *t;
};

int main()
{
	vector<int> i{ 10,9,8,4,6,2,4,19,84,41 };
	for (auto beg = i.begin(); beg != i.end(); ++beg)
		cout << (*beg % 2 ? *beg *= 2 : *beg) << ' ';
	cout << endl;
	int score = 100;
	string a = (score > 90 ? "high pass" : (score >= 75 ? "low pass" : (score >= 60 ? "pass" : "fail")));
	//auto_ptr<Test> a(new Test());
	//cout << "???" << endl;
	//a.release();
	//while (true)
	//{
	//	if (_getch() == 'q')
	//		break;
	//}
	system("pause");
	return 0;
}