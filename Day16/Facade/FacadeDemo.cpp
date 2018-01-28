#include <iostream>
#include <string>

using namespace std;


class Household
{
public:
	virtual void on() = 0;
	virtual void off() = 0;
};

class DVD : public Household
{
public:
	virtual void on()
	{
		cout << "DVD�ѿ���..." << endl;
	}
	virtual void off()
	{
		cout << "DVD�ѹػ�..." << endl;
	}
};

class GamesConsole : public Household
{
public:
	virtual void on()
	{
		cout << "��Ϸ���ѿ���..." << endl;
	}
	virtual void off()
	{
		cout << "��Ϸ���ѹػ�..." << endl;
	}
};

class TV : public Household
{
public:
	virtual void on()
	{
		cout << "TV�ѿ���..." << endl;
	}
	virtual void off()
	{
		cout << "TV�ѹػ�..." << endl;
	}
};

class Light : public Household
{
public:
	virtual void on()
	{
		cout << "����..." << endl;
	}
	virtual void off()
	{
		cout << "�ص�..." << endl;
	}
};

class Sound : public Household
{
public:
	virtual void on()
	{
		cout << "�����Ѵ�..." << endl;
	}
	virtual void off()
	{
		cout << "�����ѹر�..." << endl;
	}
};

class Microphone : public Household
{
public:
	virtual void on()
	{
		cout << "��˷��Ѵ�..." << endl;
	}
	virtual void off()
	{
		cout << "��˷��ѹر�..." << endl;
	}
};

class Facade
{
public:
	Facade()
	{
		mTV = new TV;
		mDVD = new DVD;
		mGC = new GamesConsole;
		mLight = new Light;
		mSound = new Sound;
		mMic = new Microphone;
	}
	void startGameMode()
	{
		if (mTV)
			mTV->on();
		if (mGC)
			mGC->on();
		if (mSound)
			mSound->on();
	}
	void startKTVMode()
	{
		if (mTV)
			mTV->on();
		if (mLight)
			mLight->off();
		if (mSound)
			mSound->on();
		if (mMic)
			mMic->on();
		if (mDVD)
			mDVD->on();
	}
	~Facade()
	{
		if(mTV)
			delete mTV;
		if(mDVD)
			delete mDVD;
		if(mGC)
			delete mGC;
		if(mLight)
			delete mLight;
		if(mSound)
			delete mSound;
		if(mMic)
			delete mMic;
	}

private:
	TV *mTV;
	DVD *mDVD;
	GamesConsole *mGC;
	Light *mLight;
	Sound *mSound;
	Microphone *mMic;
};

int main()
{
	Facade facade;
	facade.startGameMode();
	cout << "-----------" << endl;
	facade.startKTVMode();

	system("pause");
	return 0;
}