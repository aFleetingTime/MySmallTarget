#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <memory>
#include <vector>
#include <string>
#include <sstream>
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
	int aa;

private:
	int *t;
};

int main()
{
	int x[10], *p = x;
	cout << sizeof(x) / sizeof(*x) << endl;	//10
	cout << sizeof(p) / sizeof(*p) << endl;	//1

	//char str[] = "test";
	//constexpr size_t size = sizeof(str) / sizeof(*str);
	//char s[size];
	//memcpy(s, str, size);
	//cout << s << endl;

	//unsigned long a = ~'q' << 6;
	//bool bit = 0;
	//unsigned long index = 0;
	//string ss;
	//ss.resize(8);
	//for (auto beg = ss.begin(); beg != ss.end(); ++beg)
	//{
	//	//bit = ;
	//	*beg = (char)((bool)(a & (1UL << 8)) + 48);
	//	a <<= 1;
	//}
	//cout << ss << endl;
	//long long *p = (long long *)0x1156;
	//cout << sizeof(*p = 10) << endl;

	//cout << (3 & 7) << endl;	//3
	//cout << (3 | 7) << endl;	//7
	//cout << (3 && 7) << endl;	//true
	//cout << (3 || 7) << endl;	//true

	//vector<int> i{ 10,9,8,4,6,2,4,19,84,41 };
	//for (auto beg = i.begin(); beg != i.end(); ++beg)
	//	cout << (*beg % 2 ? *beg *= 2 : *beg) << ' ';
	//cout << endl;
	//int score = 100;
	//string a = (score > 90 ? "high pass" : (score >= 75 ? "low pass" : (score >= 60 ? "pass" : "fail")));
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