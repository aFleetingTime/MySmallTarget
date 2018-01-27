#include <iostream>
#include <string>

using namespace std;

//----------抽象层--------------
class Car
{
public:
	virtual void run() = 0;
	virtual void turn() = 0;
	virtual void stop() = 0;
	virtual string getType() = 0;
};

//----------实现层--------------
class Bus : public Car
{
public:
	Bus() : mType("巴士")
	{
	}
	virtual void run()
	{
		cout << mType << "启动了" << endl;
	}
	virtual void turn()
	{
		cout << mType << "拐弯了" << endl;
	}
	virtual void stop()
	{
		cout << mType << "停车了" << endl;
	}
	virtual string getType()
	{
		return mType;
	}

private:
	const string mType;
};

class Tractor : public Car
{
public:
	Tractor() : mType("拖拉机")
	{
	}
	virtual void run()
	{
		cout << mType << "启动了" << endl;
	}
	virtual void turn()
	{
		cout << mType << "拐弯了" << endl;
	}
	virtual void stop()
	{
		cout << mType << "停车了" << endl;
	}
	virtual string getType()
	{
		return mType;
	}

private:
	const string mType;
};

class Auto : public Car
{
public:
	Auto() : mType("汽车")
	{
	}
	virtual void run()
	{
		cout << mType << "启动了" << endl;
	}
	virtual void turn()
	{
		cout << mType << "拐弯了" << endl;
	}
	virtual void stop()
	{
		cout << mType << "停车了" << endl;
	}
	virtual string getType()
	{
		return mType;
	}

private:
	const string mType;
};


//----------业务类--------------
class Person
{
public:
	Person(string name, unsigned int age)
	{
		mName = name;
		mAge = age;
		mCar = nullptr;
	}
	void buyCars(Car *car)
	{
		if (mCar != nullptr)
			delete mCar;
		mCar = car;
		cout << mName << "买了辆" << car->getType() << endl;
	}
	void drive()
	{
		if (mCar == nullptr)
		{
			cout << mName << "还没有车!" << endl;
			return;
		}
		mCar->run();
		mCar->turn();
		mCar->stop();
	}

private:
	string mName;
	unsigned int mAge;
	Car *mCar;
};

int main()
{
	Person p1("张三", 22);
	p1.buyCars(new Tractor);
	p1.drive();
	p1.buyCars(new Bus);
	p1.drive();
	p1.buyCars(new Auto);
	p1.drive();

	system("pause");
	return 0;
}