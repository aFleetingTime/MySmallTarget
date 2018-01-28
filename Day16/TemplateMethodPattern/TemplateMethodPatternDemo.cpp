#include <iostream>
#include <string>

using namespace std;

class Scheduling
{
public:
	void StartANewDay()
	{
		Morning();
		Noon();
		Afternoon();
		Evening();
	}

private:
	virtual void Morning() = 0;
	virtual void Noon() = 0;
	virtual void Afternoon() = 0;
	virtual void Evening() = 0;
};

class XiaoMing
{
public:
	void MyDay(Scheduling *day)
	{
		day->StartANewDay();
	}
	static XiaoMing* getInstance();

private:
	XiaoMing(string name)
	{
		mName = name;
	}
	~XiaoMing() {}
	static XiaoMing *mInstance;
	string mName;
};
XiaoMing* XiaoMing::mInstance = nullptr;
XiaoMing* XiaoMing::getInstance()
{
	if (mInstance != nullptr)
		mInstance = new XiaoMing("ะกร๗");
	return mInstance;
}

class Monday : public Scheduling
{

private:
	virtual void Morning()
	{
		cout << "1" << endl;
	}
	virtual void Noon()
	{
		cout << "2" << endl;
	}
	virtual void Afternoon()
	{
		cout << "3" << endl;
	}
	virtual void Evening()
	{
		cout << "4" << endl;
	}
};

class Tuesday : public Scheduling
{

private:
	virtual void Morning()
	{
		cout << "5" << endl;
	}
	virtual void Noon()
	{
		cout << "6" << endl;
	}
	virtual void Afternoon()
	{
		cout << "7" << endl;
	}
	virtual void Evening()
	{
		cout << "8" << endl;
	}
};

void start(Scheduling *day)
{
	static XiaoMing *xm = XiaoMing::getInstance();
	xm->MyDay(day);
	delete day;
}

int main()
{
	start(new Monday);
	cout << '-' << endl;
	start(new Tuesday);

	system("pause");
	return 0;
}