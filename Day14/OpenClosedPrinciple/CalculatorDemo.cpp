#include <iostream>
#include <string>

using namespace std;

template<class T>
class Math
{
public:
	virtual T binaryOperator() = 0;
};

template<class T>
class Addition : public Math<T>
{
public:
	Addition(T a, T b)
	{
		mA = a;
		mB = b;
	}
	void setOperatorNum(T a, T b)
	{
		mA = a;
		mB = b;
	}
	virtual T binaryOperator()
	{
		return mA + mB;
	}
private:
	T mA;
	T mB;
};

template<class T>
class Subtraction : public Math<T>
{
public:
	Subtraction(T a, T b)
	{
		mA = a;
		mB = b;
	}
	void setOperatorNum(T a, T b)
	{
		mA = a;
		mB = b;
	}
	virtual T binaryOperator()
	{
		return mA - mB;
	}
private:
	T mA;
	T mB;
};

template<class T>
class Division : public Math<T>
{
public:
	Division(T a, T b)
	{
		mA = a;
		mB = b;
	}
	void setOperatorNum(T a, T b)
	{
		mA = a;
		mB = b;
	}
	virtual T binaryOperator()
	{
		return mA / mB;
	}
private:
	T mA;
	T mB;
};

template<class T>
class Modulo : public Math<T>
{
public:
	Modulo(T a, T b)
	{
		mA = a;
		mB = b;
	}
	void setOperatorNum(T a, T b)
	{
		mA = a;
		mB = b;
	}
	virtual T binaryOperator()
	{
		return mA % mB;
	}
private:
	T mA;
	T mB;
};

template<class T>
class Multiplication : public Math<T>
{
public:
	Multiplication(T a, T b)
	{
		mA = a;
		mB = b;
	}
	void setOperatorNum(T a, T b)
	{
		mA = a;
		mB = b;
	}
	virtual T binaryOperator()
	{
		return mA * mB;
	}
private:
	T mA;
	T mB;
};

template<class T>
class Calculator
{
public:
	T math(Math<T> &&m)
	{
		return m.binaryOperator();
	}
};

int main()
{
	Calculator<int> cal;
	cout << cal.math(Addition<int>(10, 20)) << endl;
	cout << cal.math(Subtraction<int>(10, 20)) << endl;
	cout << cal.math(Multiplication<int>(10, 20)) << endl;
	cout << cal.math(Division<int>(10, 20)) << endl;
	cout << cal.math(Modulo<int>(10, 20)) << endl;

	system("pause");
	return 0;
}