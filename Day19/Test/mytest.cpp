#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <memory>
#include <vector>
#include <string>
#include <sstream>
#include <array>
#include <Windows.h>
#include "mytest.h"


using namespace std;

class Test
{
public:
	Test()
	{
		cout << "Test()" << endl;
	}
	Test(const int *b, const int *e)
	{
		cout << "Test()" << endl;
	}
	int test()
	{
		void **v = nullptr;
	}
	~Test()
	{
		cout << "..." << endl;
	}
	void operator=(const Test &t)
	{
		cout << "operator=" << endl;
	}
	int aa;

};

class Word
{
public:
	Word()
	{
		wordSize = -1;
	}
	void operator+=(const string &temp)
	{
		if (temp == word)
		{
			++wordNum.at(wordSize).second;
		}
		else
		{
			word = temp;
			wordNum.emplace_back(make_pair(word, 1));
			++wordSize;
		}

	}
	pair<string, size_t>* getMax()
	{
		if (wordSize == -1)
			return nullptr;
		size_t max = 0;
		bool flag = false;
		for (int i = 1; i < wordSize - 1; ++i)
			if (wordNum[i].second > 1 && wordNum[max].second < wordNum[i].second)
			{
				max = i;
				flag = true;
			}
		return flag ? &wordNum[max] : nullptr;
	}
	vector<pair<string, size_t>> wordNum;
	string word;
	int wordSize;
};

int dive(int x = 0, const int y = 1)
{
	if (y == 0)
		throw new overflow_error("0不能作为除数");
	return x / y;
}

void fun(int *&a, int *&b)
{
	int *temp = a;
	a = b;
	b = temp;
}

void print_error(initializer_list<string> il)
{
	cout << "Error:";
	for (const string &err_info : il)
		cout << err_info << ' ';
	cout << endl;
}

int sum(initializer_list<int> il)
{
	int sumNum = 0;
	for (const int &i : il)
		sumNum += i;
	return sumNum;
}

const char &ttt(const string &str, string::size_type index)
{
	return str[index];
}

//void print(const vector<int> &vec, int index)
//{
//	if (index == vec.size())
//		return;
//	cout << vec[index] << endl;
//	print(vec, index + 1);
//}

void print(vector<int>::iterator beg, vector<int>::iterator End)
{
	if (beg == End)
		return;
	cout << *beg << endl;
	print(beg + 1, End);
}

int fa(int val)
{
	if (val != 0)
		return fa(val - 1) * val;
	return 1;
}

//int(*testa(int s))[10]
//{
//	int a[10][10];
//	return a;
//}
//auto testa(int s) -> int(*)[10]
//{
//	return new int[10][10];
//}
//using MyType = int(*)[10];
//MyType testa(int s)
//{
//	int a[10][10];
//	return a;
//}
int a[10][10];
//decltype(a)* testa(int s)
//{
//	return &a;
//}
decltype(a)& testa(int s)
{
	return a;
}

//string * const & testtt(string * const &s)
//{
//	return s;
//}
string (&testtt(string (&s)[10]))[10]
{
	return s;
}

void overloaded(int a)
{
	cout << "int" << endl;
}

void overloaded(string a)
{
	cout << "string" << endl;
}

void overloaded(char c)
{
	cout << "char" << endl;
}

void foo()
{
	void overloaded(char c);
	void overloaded(string a);
	overloaded("1");
}

void aaa(int a = 0, int b = 0);
void aaa(int a, int bx)
{

}
constexpr int aaaa(const int a)
{
	return a;
}


//void f(double a, double b = 3.14)
//{
//	cout << "double double" << endl;
//}
void f(int a, int b)
{
	cout << "int int" << endl;
}
void f(const int *a)
{
	cout << "const int" << endl;
}
//void f(const int &a, const int &b)
//{
//	cout << "const int  const int" << endl;
//}
void f()
{
	cout << "void" << endl;
}

//void (*func(int a))(int, int)
//{
//	return f;
//}
auto func(int a) -> void(*)(int,int)
{
	return f;
}
//decltype(f(0,0)) *func(int a)
//{
//	return f;
//}

istream &st(istream &s)
{
	int a = 0;
	s >> a;
	return s;
}

Test ttttt()
{
	Test A;
	Test B = A;
	return B;
}


class ClassT
{
public:
	ClassT() = default;
	ClassT(int a)
	{

	}
	int a;
};
Test ttttt();
class Class
{
	friend Test ttttt();
public:
	using myint = int;
	void t() const
	{
		
	}
	Class(int aa = 0) : b(2), c(3)
	{
		
	}
	inline void testt() const;
	vector<int> v{10,10};
	mutable int b;
	int c;
	int a = b + c;
	//int a;
	//int b;
	//int c;
};

inline void Class::testt() const
{
	Class *consta = const_cast<Class*>(this);
	consta->a = 10000;
}

class Screen
{
public:
	using pos_t = string::size_type;
	Screen() = default;
	Screen(pos_t h, pos_t w, char c = ' ') : ht(h), wd(w), contents(h * w, c) {}
	void some_member() const;
private:
	pos_t ht = 0, wd = 0;
	string contents;
	mutable size_t count = 0;
};

void Screen::some_member() const
{
	++count;
}

class Window
{
public:
private:
	vector<Screen> screens{ 10, Screen(10, 20) };
};

template<typename T1, typename T2>
class C1
{
public:
	static constexpr bool value = false;
};
//template<typename T1, typename T2>
//constexpr bool C1<T1, T2>::value = false;

template<typename T>
class C1<T, T>
{
public:
	static constexpr bool value = true;
};
//template<typename T>
//constexpr bool C1<T, T>::value = true;

template<typename Type1, Type1 Type2>
struct Compare
{
	static constexpr bool value = Type2;
};
using trueType = Compare<bool, true>;
using falseType = Compare<bool, false>;

template<typename Type1, typename Type2>
struct my_is_same : falseType
{
};
template<typename Type1>
struct my_is_same<Type1, Type1> : trueType
{
};

int main()
{
	Class a;
	a.testt();
	cout << a.a << endl;

	//const int *const a = nullptr;
	//int **b = const_cast<int**const>(&a);
	//int i = 100;
	//*b = &i;
	//if (a == nullptr)
	//	cout << "nullptr" << endl;


	//cout << my_is_same<int, int>::value << endl;
	//cout << C1<int, double>::value << endl;
	//cout << is_same<int, double>::value << endl;
	//C1<int, double> c;
	//int a = 2;
	//cout << a << " " << a++ << endl;

	//Class s;
	//cout << s.a << endl;

	//Test a;
	//const_cast<const Test>(a);

	//ttttt();

	//Test(Test()).
	//vector<void(*(int))(int, int)> v;
	//v.push_back(func);

	//string s("aaaaa");
	//constexpr int i = 0;
	//int a = s.size();

	//const int a = 0;
	//f(&a);

	////f(2.56, 42);
	//f(42);
	//f(42, 0);
	//f(2.56, 3.14);

	//int i = 1;
	//aaaa(i);
	//cout << sss("aaa") << endl;
	//int a[];


	//string s[10];
	//string * const &p = s;
	//string (&p)[10] = s;
	//cout << p[11] << endl;
	//testtt(s)[1];

	//delete[] testa(1);

	//cout << fa(5) << endl;

	//vector<int> vec{ 10,20,30,40,50,60,7,80,89 };
	//print(vec.begin(), vec.end());

	//vector<int> vec(10, 10);
	//cout << sum(initializer_list<int>(vec.data(), vec.data() + vec.size())) << endl;
	////make_error_code(errc::io_error);
	//print_error({"a"});
	//print_error({ "a" , "bbb"});

	//int a = 1, b = 2;
	//int *ap = &a, *ab = &b;
	//cout << *ap << ' ' << *ab << endl;
	//fun(ap, ab);
	//cout << *ap << ' ' << *ab << endl;

	//vector<int&> v;
	//int a = 0;
	//v.push_back(a);

	//int a[10]{};
	//int *p = begin(a);

	//int a = 3.8;
	//cout << a << endl;

	//const String &a = "aaa";

	//cout << dive(1, 1);
	//cout << dive(8, 1);

	//int x = 0, y = 0;
	//while (cin >> x >> y)
	//{
	//	try
	//	{
	//		int num = dive(x, y);
	//		cout << "商:" << num << endl;
	//	}
	//	catch (overflow_error *err)
	//	{
	//		cout << err->what() << endl;
	//		cout << "是否继续?" << endl;
	//		char c = 0;
	//		cin >> c;
	//		if (!cin || c == 'n')
	//			break;
	//	}
	//}

	//string str;
	//string old;
	//bool flag = true;
	//
	//while (cin >> str)
	//{
	//	if (!isupper(str.front()))
	//		continue;
	//	if (str == old)
	//	{
	//		cout << str << endl;
	//		flag = false;
	//		break;
	//	}
	//	old = str;
	//}

	//if (flag)
	//	cout << "没有连续出现的字符串" << endl;
	//exception a;
	//cout << a.what() << endl;
	//vector<int> vec = { 10, 20,30, 40,50,90,44 };
	//vec.reserve(10);
	//for (int &a : vec)
	//{
	//	cout << a << endl;
	//	vec.push_back(a);
	//	Sleep(1);
	//}

	//vector<Word> data;
	//string temp, cur;
	//Word word;
	//while (cin >> temp)
	//	word += temp;
	//pair<string, size_t> *max = word.getMax();
	//if (max != nullptr)
	//	cout << "Word: " << max->first << "  count: " << max->second << endl;
	//else
	//	cout << "没有重复出现的单词" << endl;

//	goto T;
//	int a;
//T:
//	a = 100;

	//switch ('c')
	//{
	//case 'a': case 'b': case 'c':
	////{
	//	int a;
	//	a = 100;
	////}
	//case 'd':
	//	a = 1;
	//cout << "1" << endl;
	//}

	//array<string, 6> scores = { "E","D", "C", "B", "A" ,"A++" };
	//int socre = 0;
	//cin >> socre;
	//string s;

	//socre < 60 ? s = scores[0] : s = scores[(socre - 50) / 10],socre % 10 > 7 ? s += "+" : socre != 100 && socre % 10 < 3 ? s += "-" : s;

	//cout << s << endl;

	//if (!socre)
	//	;
	//else s = s = 1000;

	//cout << s << endl;

	//string s;
	//while (string::iterator a != s.end());

	//int *p = nullptr;
	//for (int i = 0; i < 10; ++i)
	//	p = &i;
	//cout << (*p = 1999) << endl;

	//{
	//	Test a;
	//}
	//cout << (*p = 1999) << endl;

	//{
	//	int val = 11;
	//	int sum = 0;
	//	while (sum += val, ++val <= 10);

	//	cout << sum << endl;
	//}
	//{
	//	int val = 11;
	//	int sum = 0;
	//	while (val <= 10)
	//	{
	//		sum += val;
	//		++val;
	//	}

	//	cout << sum << endl;
	//}
	
	//int a = 15641561;
	//int *b = &a;
	//const_cast<const int*>(b);
	//int *ip = &a;
	//char *cp = reinterpret_cast<char*>(ip);
	//cout << string(cp) << endl;

	//int s = 100;
	//const int *p = &s;
	//*const_cast<int*>(p) = 200;
	//cout << *p << endl;
	//reinterpret_cast<>(s) = 200;
	//cout << static_cast<string>("test") << endl;

	//const int * const p = nullptr;
	//void *a = (void*)p;

	//int x[10], *p = x;
	//cout << sizeof(x) / sizeof(*x) << endl;	//10
	//cout << sizeof(p) / sizeof(*p) << endl;	//1

	//int a = 0, b = 0;
	//cout << sizeof (a < b) << endl;

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