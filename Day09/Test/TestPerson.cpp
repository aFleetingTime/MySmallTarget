#pragma once
#include "TestPerson.h"

template<class T>
TestPerson<T>::TestPerson(T a, T b)
{
	this->a = a;
	this->b = b;
}

template<class T>
TestPerson<T>::~TestPerson()
{
}

template<class T>
void TestPerson<T>::show()
{
	std::cout << "A:" << a << std::endl;
	std::cout << "B:" << b << std::endl;
}

template<class T>
void print(TestPerson<T> &per)
{
	std::cout << "A:" << per.a << std::endl;
	std::cout << "B:" << per.b << std::endl;
}
