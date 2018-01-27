#include <iostream>
#include <string>

using namespace std;

//懒汉式
class Singleton1
{
public:
	static Singleton1 * getInstance()
	{
		if (mInstance == nullptr)
			mInstance = new Singleton1;
		return mInstance;
	}
	void show()
	{
		cout << "单例模式:懒汉式" << endl;
	}
private:
	Singleton1() { cout << "Singleton1 Run..." << endl; }
	~Singleton1() { cout << "~Singleton1 Run..." << endl; }
	static Singleton1 *mInstance;
	class MyGC
	{
	public:
		MyGC()
		{
			cout << "GC1 Run..." << endl;
		}
		~MyGC()
		{
			if (mInstance != nullptr)
			{
				delete mInstance;
				cout << "~GC1 Run..." << endl;
			}
			system("pause");
		}
	};
	static MyGC gc;
};
Singleton1* Singleton1::mInstance = nullptr;
Singleton1::MyGC Singleton1::gc;

//饿汉式
class Singleton2
{
public:
	static Singleton2 * getInstance()
	{
		return mInstance;
	}
	void show()
	{
		cout << "单例模式:饿汉式" << endl;
	}
private:
	Singleton2() { cout << "Singleton2 Run..." << endl; }
	~Singleton2() { cout << "Singleton2 Run..." << endl; }
	static Singleton2 *mInstance;
	class MyGC
	{
	public:
		MyGC()
		{
			cout << "GC2 Run..." << endl;
		}
		~MyGC()
		{
			if (mInstance != nullptr)
			{
				delete mInstance;
				cout << "~GC2 Run..." << endl;
			}
			system("pause");
		}
	};
	static MyGC gc;
};
Singleton2* Singleton2::mInstance = new Singleton2;
Singleton2::MyGC Singleton2::gc;

int main()
{
	Singleton1 *s1 = Singleton1::getInstance();
	s1->show();

	if (s1 == Singleton1::getInstance())
		cout << "单利" << endl;

	Singleton2 *s2 = Singleton2::getInstance();
	s2->show();

	if (s2 == Singleton2::getInstance())
		cout << "单利" << endl;

	cout << "-------------" << endl;

	//system("pause");
	return 0;
}