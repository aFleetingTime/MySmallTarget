#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Fruit
{
public:
	virtual void show() = 0;
};
class FruitFactory
{
public:
	virtual Fruit* createObject() = 0;
};

class Apple : public Fruit
{
public:
	friend class AppleFactory;
	virtual void show()
	{
		cout << "ƻ��" << endl;
	}

private:
	Apple() {};
};

class Banana : public Fruit
{
public:
	friend class BananaFactory;
	virtual void show()
	{
		cout << "�㽶" << endl;
	}

private:
	Banana() {};
};

class AppleFactory : public FruitFactory
{
public:
	virtual Fruit* createObject()
	{
		return new Apple;
	}
};

class BananaFactory : public FruitFactory
{
public:
	virtual Fruit* createObject()
	{
		return new Banana;
	}
};

#if 0
template<class T>
class NewFactory
{
public:
	Fruit * createObject()
	{
		return new T;
	}
};
#endif

Fruit* createFruitObject(FruitFactory *factory)
{
	Fruit *temp = factory->createObject();
	delete factory;
	return temp;
}
void test1()
{


		int num = 0;
		vector<int> ivec;
		cin >> num;
		switch (num)
		{
		case num>100:
		}
		return 0;
}

int main()
{
	Apple *apple = reinterpret_cast<Apple*>(createFruitObject(new AppleFactory));
	if (apple != nullptr)
	{
		apple->show();
		delete apple;
	}
	Fruit *banana = createFruitObject(new BananaFactory);
	if (banana != nullptr)
	{
		banana->show();
		delete banana;
	}
	cout << "Test" << endl;

	system("pause");
	return 0;
}