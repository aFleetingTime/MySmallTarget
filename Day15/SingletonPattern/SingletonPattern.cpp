#include <iostream>
#include <string>
#include <windows.h>
#include <process.h>
#include <mutex>

using namespace std;

static mutex cc;

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
};
Singleton1* Singleton1::mInstance = nullptr;

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
};
Singleton2* Singleton2::mInstance = new Singleton2;

//懒汉式
class Singleton3
{
public:
	static Singleton3 * getInstance()
	{
		if (mInstance == nullptr)
		{
			cc.lock();
			if (mInstance == nullptr)
			{
				mInstance = new Singleton3;
			}
			cc.unlock();
		}
		return mInstance;
	}
	void show()
	{
		cc.lock();
		cout << "懒汉式多线程测试..." << endl;
		cc.unlock();
	}
private:
	Singleton3() { cout << "Singleton3 Run..." << endl; }
	~Singleton3() { cout << "~Singleton3 Run..." << endl; }
	static Singleton3 *mInstance;
};
Singleton3* Singleton3::mInstance = nullptr;

void test(void *)
{
	Singleton3::getInstance()->show();
}

int main()
{
#if 0
	Singleton1 *s1 = Singleton1::getInstance();
	s1->show();

	if (s1 == Singleton1::getInstance())
		cout << "单利" << endl;

	Singleton2 *s2 = Singleton2::getInstance();
	s2->show();

	if (s2 == Singleton2::getInstance())
		cout << "单利" << endl;

	cout << "-------------" << endl;
#endif
	HANDLE threads[10];
	for (int i = 0; i < 3; ++i)
	{
		threads[i] = reinterpret_cast<HANDLE>(_beginthread(test, 0, nullptr));
	}
	for (int i = 0; i < 3; ++i)
	{
		WaitForSingleObject(threads[i], INFINITE);
	}
	system("pause");
	return 0;
}