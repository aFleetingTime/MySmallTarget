#include <iostream>
#include <string>

using namespace std;

class Fruit
{
public:
	virtual void show() = 0;
};

class Apple : public Fruit
{
public:
	friend class Factory;
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
	friend class Factory;
	virtual void show()
	{
		cout << "Ïã½¶" << endl;
	}
	friend Factory;

private:
	Banana() {};
};

class Factory
{
public:
	friend class Apple;
	Fruit* createObject(string objName)
	{
		if (!objName.compare("Apple"))
			return new Apple;
		else if (!objName.compare("Banana"))
			return new Banana;
		else
			return nullptr;
	}
};

#if 0
template<class T>
class NewFactory
{
public:
	Fruit* createObject()
	{
		return new T;
	}
};
#endif

int main()
{
	Factory factory;
	Apple *apple = reinterpret_cast<Apple*>(factory.createObject("Apple"));
	if (apple != nullptr)
	{
		apple->show();
		delete apple;
	}
	Fruit *banana = factory.createObject("Banana");
	if (banana != nullptr)
	{
		banana->show();
		delete banana;
	}

	system("pause");
	return 0;
}

