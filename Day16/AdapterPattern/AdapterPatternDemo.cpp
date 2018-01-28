#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template<class First, class Scoend>
class MyPrintTest1
{
public:
	void operator()(First a, Scoend b) const
	{
		cout << a << ' ' << b << endl;
	}
};

template<class T>
class Target
{
public:
	virtual void operator()(T a) = 0;
};

template<class Fn, class Ty, class T>
struct MyBind2 : public Target<T>
{
	MyBind2(const Fn &obj, const Ty &value) : mObj(obj), mValue(value) {}
	virtual void operator()(T t)
	{
		mObj(t, mValue);
	}
	const Fn &mObj;
	const Ty &mValue;
};

template<class Fn, class Ty, class T>
MyBind2<Fn, Ty, T> MyBind2nd(const Fn &obj, const Ty &value)
{
	return MyBind2<Fn, Ty, T>(obj, value);
}

int main()
{
	vector<string> ivec;
	ivec.emplace_back("aaaaaaaaaaaa");
	ivec.emplace_back("bbbbbbbbbbb");
	
	for_each(ivec.begin(), ivec.end(), MyBind2nd<MyPrintTest1<string, double>, double, string>(MyPrintTest1<string, double>(), 0.136));

	system("pause");
	return 0;
}