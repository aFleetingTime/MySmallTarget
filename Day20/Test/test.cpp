#include <iostream>
#include <string>
#include <iterator>
#include <random>
#include <valarray>
#include <array>
#include <fstream>
#include <ObjectArray.h>

using namespace std;

constexpr int x = 5, y = 10;
random_device random;

void initArray(int (*p)[y])
{
	for (int (*t)[y] = p; t != p + x; ++t)
	{
		for (int *a = *t; a != *t + y; ++a)
			*a = random() % 50;
	}
}

void test1(int (*const &p)[10])
{
	//for(int (*a)[y] : p)
	//for (const auto &s : p)
	//{
	//	for (auto a : s)
	//		cout << a << ' ';
	//	cout << endl;
	//}
}

struct Y; struct X;

struct X
{
	Y *y;
};
using a = int;
struct Y
{
	a test()
	{

	}
	using a = double;
	X x;
};

class Exercise
{
public:
	Exercise(int a, int b)
	{
		cout << "(int,int)" << endl;

	}
	Exercise(int a) : Exercise(a, 1)
	{
		cout << "(int)" << endl;

	}
	Exercise() : Exercise(1)
	{
		cout << "(void)" << endl;

	}

private:
	int val;
};

class Date
{
public:
	Date(const string &year, const string &month = "01", const string &day = "01") : mYear(year), mMonth(month), mDay(day) {}
	Date() : Date("2018") {}

private:
	string mYear;
	string mMonth;
	string mDay;
};

struct NoDefault
{
	NoDefault(int num)
	{

	}
};

struct C
{
public:
	C() : nod(0)
	{

	}

private:
	NoDefault nod;
};

struct MyClass
{
	MyClass(const string &str)
	{
		cout << "MyClass(string)" << endl;
	}
	MyClass(const MyClass &str)
	{
		cout << "MyClass(MyClass)" << endl;
	}
	void operator=(const MyClass &str)
	{
		cout << "MyClass(MyClass)" << endl;
	}
};

void function1(MyClass c)
{

}
void function2(MyClass &&c)
{

}
void function3(const MyClass &c)
{

}
int ff = 1;
void function3(int a = ff)
{

}
//constexpr int aaa(int &a)
//{
//	//a = 10;
//	return a;
//}

class Debug1
{
public:
	constexpr Debug1(bool b = flag) : Debug1(b, b, b) { }
	constexpr Debug1(bool ib, bool hb, bool ob) : IOError(ib), HWError(hb), OTError(ob), arr{} { }
	constexpr bool any() const { return IOError || HWError || OTError; }
	void setIO(bool b) { IOError = b; }
	void setHW(bool b) { HWError = b; }
	void setOT(bool b) { OTError = b; }
	static void setFlag(bool b) { flag = b; }
	static constexpr int ss = 10;

private:
	bool IOError;
	bool HWError;
	bool OTError;
	static bool flag;
	int arr[ss];
	static vector<double> dd;
};
bool Debug1::flag = true;
vector<double> Debug1::dd(ss);
constexpr int Debug1::ss;

void f(istream &i, ostream &o, ostream &e)
{
	int s = 0;
	while (i >> s || !i)
	{
		istream::iostate state = i.rdstate();
		if (state & istream::failbit)
		{
			e << "输入的数据类型错误" << endl;
			i.clear();
		}
		else
			o << s << endl;
	}
}

istream &getdata(istream &is)
{
	string str;
	while (!is.eof())
	{
		string temp;
		is >> temp;
		str += temp + ' ';
	}
	cout << str << endl;
	is.clear(is.rdstate() & ~istream::eofbit);
	return is;
}
istream &funcc(istream &is)
{
	ios::_Myos *p = is.tie();
	if (p == &cout)
		cout << "cout" << endl;
	ofstream ofs;
	is.tie(&ofs);
	return is;
}

struct Teest
{
	Teest(char *p) { cout << "const char *" << endl; }
	Teest(const string &s) { cout << "const string &" << endl; }
};

using sss = string;

int main()
{
	string ssss("bbbb");
	"aaaa" + ssss;
	cout << boolalpha << cout.eof() << endl;
	sss s;
	string ss;
	s = ss;
	cout << ios::out << endl;
	cout << ios::in << endl;


	//if (cout.tie() == nullptr)
	//	cout << "nullptr" << endl;
	//ostream *p = cerr.tie();
	//ifstream(string("a"),)
	//p->put('a');

	//funcc(cin);
	//int i = 0;
	//cin >> i;

	/*cout.tie(&cout);
	cin.tie(&cout);
	cin.tie(&cout);*/

	//cout << "a";
	//cout << unitbuf << "a";
	//streambuf *buf = cout.rdbuf();
	//buf->sputn("aaa", 3);

	//Sleep(10000);
	//getdata(cin);

	//cout << boolalpha << is_same<iostream::iostate, short>::value << endl;
	//cout << (cin.rdstate() | cin.failbit | cin.badbit) << endl;
	//cout << cin.rdstate() << endl;
	//cout << (cin.rdstate() & cin.failbit & cin.badbit) << endl;
	//cin.setstate(cin.failbit | cin.badbit | cin.eofbit);
	//cout << endl;
	//cout << cin.rdstate() << endl;
	//cout << (cin.rdstate() & ~cin.failbit & ~cin.badbit) << endl;

	//wstringbuf a;
	//wstring a;
	//ostream::iostate;
	////streambuf s;
	//ofstream a("a", );
	//int a;
	//wcin >> a;
	//wcout << a << endl;

	//int a[Debug1::aaa]
	//constexpr Debug1 deb;
	//Debug1 d;
	//cout << boolalpha << d.any() << endl;
	//Debug1::setFlag(false);
	//Debug1 db;
	//cout << boolalpha << db.any() << endl;

	//int i = 2 + 1;
	//int ss[aaa(3)];
	//cout << i << endl;
	//MyClass &&y = MyClass(string("aa"));
	//string s("aaa");
	//function1(s);
	//function2(s);
	//function3(s);

	//MyClass a("aaa");
	//MyClass a("aaa");
	//function(string("a"));

	//C a;
	////vector<NoDefault> v(10, NoDefault(10));
	//vector<C> v(10);
	//Exercise();
	//using a = int;
	//using a = int;

	//Exercise aa;
	//Y y;
	//y.x.y = &y;
	//y.x.y->x.y->x.y->x.y->x.y->x.y->x.y->x.y->x.y->x;


	////int array[x][y]{};
	//array<int, x> A{1,2,3,4,5};
	////initArray(array);
	//
	//valarray<int> a(A.data(), 5);
	//a.apply();
	//test1(array);
	//for (const auto &p : array)
	//{
	//	for (auto a : p)
	//		cout << a << ' ';
	//	cout << endl;
	//}
	//cout << (a += 10).min() << endl;

	system("pause");
	return 0;
}