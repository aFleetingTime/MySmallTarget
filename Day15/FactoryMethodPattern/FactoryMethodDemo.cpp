#include <iostream>
#include <string>

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
		cout << "Æ»¹û" << endl;
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
		cout << "Ïã½¶" << endl;
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

	system("pause");
	return 0;
}