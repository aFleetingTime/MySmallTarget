#include <iostream>
#include <string>

using namespace std;

class House
{
public:
	virtual void setWindow(string window) = 0;
	virtual void setWall(string wall) = 0;
	virtual void setFloor(string floor) = 0;
	virtual void setDoor(string door) = 0;
	virtual void showHouse() = 0;

protected:
	string mWindow;
	string mWall;
	string mFloor;
	string mDoor;
	string mType;
};

class CommonHouse : public House
{
public:
	void setWindow(string window)
	{
		mWindow = window;
		mType = "∆’Õ®∑ø";
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
		cout << mType << endl;
		cout << mWindow << endl;
		cout << mWall << endl;
		cout << mFloor << endl;
		cout << mDoor << endl;
	}
};

class LuxuryHouse : public House
{
public:
	void setWindow(string window)
	{
		mWindow = window;
		mType = "∫¿ª™∑ø";
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
		cout << mType << endl;
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
		mHouse->setWindow("≤£¡ß¥∞");
	}
	virtual void createWall()
	{
		mHouse->setWall("ªÏƒ˝Õ¡«Ω");
	}
	virtual void createFloor()
	{
		mHouse->setFloor("¥…µÿ∞Â");
	}
	virtual void createDoor()
	{
		mHouse->setDoor("Ã˙√≈");
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
		mHouse->setWindow("ƒæ¥∞");
	}
	virtual void createWall()
	{
		mHouse->setWall(" Ø«Ω");
	}
	virtual void createFloor()
	{
		mHouse->setFloor(" Ø∞Â");
	}
	virtual void createDoor()
	{
		mHouse->setDoor("ƒæ√≈");
	}
	virtual House* getHouse()
	{
		return mHouse;
	}
};

class Director
{
public:
	Director(Builder *b) : mBuilder(b) {}
	virtual House* createHouse() = 0;

protected:
	Builder * mBuilder;
};

class CommonDirector : public Director
{
public:
	CommonDirector(Builder *builder) : Director(builder) {}
	House* createHouse()
	{
		mBuilder->createDoor();
		mBuilder->createFloor();
		mBuilder->createWall();
		mBuilder->createWindow();
		return mBuilder->getHouse();
	}
};

class LuxuryDirector : public Director
{
public:
	LuxuryDirector(Builder *builder) : Director(builder) {}
	House* createHouse()
	{
		mBuilder->createWindow();
		mBuilder->createFloor();
		mBuilder->createDoor();
		mBuilder->createWall();
		return mBuilder->getHouse();
	}
};

int main()
{
	House *house = new CommonHouse();
	Builder *builder = new BuilderA(house);
	Director *director = new CommonDirector(builder);

	cout << "-------BuilderA-------" << endl;

	director->createHouse();
	house->showHouse();

	delete director;
	delete builder;
	delete house;

	cout << "-------BuilderB-------" << endl;

	house = new LuxuryHouse;
	builder = new BuilderB(house);
	director = new LuxuryDirector(builder);

	director->createHouse();
	house->showHouse();

	delete director;
	delete builder;
	delete house;

	system("pause");
	return 0;
}