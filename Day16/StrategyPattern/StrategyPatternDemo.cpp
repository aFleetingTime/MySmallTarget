#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Equipment
{
public:
	Equipment(unsigned ad, unsigned ap, string name) : mAd(ad), mAp(ap), mName(name) {}
	virtual unsigned getAd() = 0;
	virtual unsigned getAp() = 0;
	virtual string getName() = 0;

protected:
	const unsigned mAd;
	const unsigned mAp;
	const string mName;
};

class Endless : public Equipment
{
public:
	Endless() : Equipment(80, 0, "无尽") {}
	virtual unsigned getAd()
	{
		return mAd;
	}
	virtual unsigned getAp()
	{
		return mAp;
	}
	virtual string getName()
	{
		return mName;
	}
};

class Hero
{
public:
	virtual ~Hero()
	{
		for (Equipment *p : mEquipment)
		{
			if (p != nullptr)
				delete p;
		}
	}
	virtual void showAd() = 0;
	virtual void showAp() = 0;
	virtual void purchaseEquipment(Equipment *equip) = 0;
	virtual void showEquipment() = 0;
protected:
	unsigned mAd;
	unsigned mAp;
	string mName;
	vector<Equipment*> mEquipment;
};

class JS : public Hero
{
public:
	JS()
	{
		mAd = 68;
		mAp = 0;
		mName = "JS";
	}
	virtual void showAd()
	{
		cout << mName << "的AD为:" << mAd << endl;
	}
	virtual void showAp()
	{
		cout << mName << "的AP为:" << mAp << endl;
	}
	virtual void purchaseEquipment(Equipment *equip)
	{
		cout << mName << "购买了" << equip->getName() << endl;
		mAd += equip->getAd();
		mAp += equip->getAp();
		mEquipment.push_back(equip);
	}
	virtual void showEquipment()
	{
		int count = 1;
		for (Equipment *p : mEquipment)
		{
			if (p != nullptr)
				cout << count++ << '.' << p->getName() << endl;
		}
	}
};

void start(Hero *hero)
{
	for(int i = 0; i != 6; ++i)
		hero->purchaseEquipment(new Endless);
	hero->showEquipment();
	hero->showAd();
	hero->showAp();
	delete hero;
}

int main()
{
	start(new JS);

	system("pause");
	return 0;
}