#include <iostream>
#include <string>

using namespace std;

//----------�����--------------
class Car
{
public:
	virtual void run() = 0;
	virtual void turn() = 0;
	virtual void stop() = 0;
	virtual string getType() = 0;
};

//----------ʵ�ֲ�--------------
class Bus : public Car
{
public:
	Bus() : mType("��ʿ")
	{
	}
	virtual void run()
	{
		cout << mType << "������" << endl;
	}
	virtual void turn()
	{
		cout << mType << "������" << endl;
	}
	virtual void stop()
	{
		cout << mType << "ͣ����" << endl;
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
	Tractor() : mType("������")
	{
	}
	virtual void run()
	{
		cout << mType << "������" << endl;
	}
	virtual void turn()
	{
		cout << mType << "������" << endl;
	}
	virtual void stop()
	{
		cout << mType << "ͣ����" << endl;
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
	Auto() : mType("����")
	{
	}
	virtual void run()
	{
		cout << mType << "������" << endl;
	}
	virtual void turn()
	{
		cout << mType << "������" << endl;
	}
	virtual void stop()
	{
		cout << mType << "ͣ����" << endl;
	}
	virtual string getType()
	{
		return mType;
	}

private:
	const string mType;
};


//----------ҵ����--------------
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
		cout << mName << "������" << car->getType() << endl;
	}
	void drive()
	{
		if (mCar == nullptr)
		{
			cout << mName << "��û�г�!" << endl;
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
	Person p1("����", 22);
	p1.buyCars(new Tractor);
	p1.drive();
	p1.buyCars(new Bus);
	p1.drive();
	p1.buyCars(new Auto);
	p1.drive();

	system("pause");
	return 0;
}