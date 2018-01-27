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
	virtual void show()
	{
		cout << "Æ»¹û" << endl;
	}

private:
	const string mName;
};

class Banana : public Fruit
{
public:
	virtual void show()
	{
		cout << "Ïã½¶" << endl;
	}

private:
	const string mName;
};

class Factory
{
public:
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

template<class T>
class NewFactory
{
public:
	Fruit* createObject()
	{
		return new T;
	}
};

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

	Fruit *nApple = NewFactory<Apple>().createObject();
	if (nApple != nullptr)
	{
		nApple->show();
		delete nApple;
	}

	system("pause");
	return 0;
}

