#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AbstractHero
{
public:
	AbstractHero() : HP(0), MP(0), AD(0), AP(0) {}
	virtual void showAttribute() = 0;

public:
	int HP;
	int MP;
	int AD;
	int AP;
};

class Hero : public AbstractHero
{
public:
	virtual void showAttribute()
	{
		cout << "Hero" << endl;
		cout << "HP:" << HP << endl;
		cout << "MP:" << MP << endl;
		cout << "AD:" << AD << endl;
		cout << "AP:" << AP << endl;
	}
};

class AbstractEquipmentHero : public AbstractHero
{
public:
	AbstractEquipmentHero(AbstractHero *hero) { mHero = hero; }
	virtual void showAttribute() = 0;
	virtual ~AbstractEquipmentHero()
	{
		if (mHero)
			delete mHero;
	}

private:
	AbstractHero *mHero;
};

class SuperHero : public AbstractEquipmentHero
{
public:
	SuperHero(AbstractHero *hero) : AbstractEquipmentHero(hero)
	{
		mHero = hero;
		if (mHero != nullptr)
		{
			HP = mHero->HP + 10000;
			MP = mHero->MP + 10000;
			AD = mHero->AD + 10000;
			AP = mHero->AP + 10000;
		}
	}
	virtual void showAttribute()
	{
		cout << "SuperHero" << endl;
		cout << "HP:" << HP << endl;
		cout << "MP:" << MP << endl;
		cout << "AD:" << AD << endl;
		cout << "AP:" << AP << endl;
	}

private:
	AbstractHero * mHero;
};

void test()
{
	Hero h;
	h.showAttribute();

	cout << "---------" << endl;

	SuperHero sh(new Hero);
	sh.showAttribute();
}

int main()
{
	test();

	system("pause");
	return 0;
}