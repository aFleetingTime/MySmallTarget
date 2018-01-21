#pragma once
#include <iostream>

template<class T> class TestPerson;
template<class T> void print(TestPerson<T> &);

template<class T>
class TestPerson
{
public:
	TestPerson(T, T);
	~TestPerson();
	void show();
	friend void print<T>(TestPerson<T> &);

private:
	T a;
	T b;
};

