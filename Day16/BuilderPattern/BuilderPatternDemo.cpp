#include <iostream>
#include <string>

using namespace std;

class House
{
public:
	void setWindow(string window)
	{
		mWindow = window;
	}
	void setWall(string wall)
	{
		mWall = wall;
	}
	void setFloor(string floor)
	{
		mFloor = floor;
	}
	void setDoor(string door)
	{
		mDoor = door;
	}
	void showHouse()
	{
		cout << mWindow << endl;
		cout << mWall << endl;
		cout << mFloor << endl;
		cout << mDoor << endl;
	}

private:
	string mWindow;
	string mWall;
	string mFloor;
	string mDoor;
};

class Builder
{
public:
	Builder(House *house)
	{
		mHouse = house;
	}
	virtual void createWindow() = 0;
	virtual void createWall() = 0;
	virtual void createFloor() = 0;
	virtual void createDoor() = 0;
	virtual House* getHouse() = 0;

protected:
	House *mHouse;
};

class BuilderA : public Builder
{
public:
	BuilderA(House *house) : Builder(house) {}
	virtual void createWindow()
	{
		mHouse->setWindow("������");
	}
	virtual void createWall()
	{
		mHouse->setWall("������ǽ");
	}
	virtual void createFloor()
	{
		mHouse->setFloor("�ɵذ�");
	}
	virtual void createDoor()
	{
		mHouse->setDoor("����");
	}
	virtual House* getHouse()
	{
		return mHouse;
	}
};

class BuilderB : public Builder
{
public:
	BuilderB(House *house) : Builder(house) {}
	virtual void createWindow()
	{
		mHouse->setWindow("ľ��");
	}
	virtual void createWall()
	{
		mHouse->setWall("ʯǽ");
	}
	virtual void createFloor()
	{
		mHouse->setFloor("ʯ��");
	}
	virtual void createDoor()
	{
		mHouse->setDoor("ľ��");
	}
	virtual House* getHouse()
	{
		return mHouse;
	}
};

class Director
{
public:
	Director(Builder *builder)
	{
		mBuilder = builder;
	}
	House* createHouse()
	{
		mBuilder->createDoor();
		mBuilder->createFloor();
		mBuilder->createWall();
		mBuilder->createWindow();
		return mBuilder->getHouse();
	}

private:
	Builder *mBuilder;
};

int main()
{
	House *house = new House();
	Builder *builder = new BuilderA(house);
	Director *director = new Director(builder);

	cout << "-------BuilderA-------" << endl;

	director->createHouse();
	house->showHouse();

	delete director;
	delete builder;

	cout << "-------BuilderB-------" << endl;

	builder = new BuilderB(house);
	director = new Director(builder);

	director->createHouse();
	house->showHouse();

	delete director;
	delete builder;
	delete house;

	system("pause");
	return 0;
}