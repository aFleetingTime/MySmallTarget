#include <iostream>
#include <string>

using namespace std;

void test()
{
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
			cout << "ƻ��" << endl;
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
			cout << "�㽶" << endl;
		}

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
	}
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
}
int main()
{
#if 0
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
#endif
	test();

	system("pause");
	return 0;
}

