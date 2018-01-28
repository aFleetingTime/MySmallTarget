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
	const int HP;
	const int MP;
	const int AD;
	const int AP;
};

class Hero : AbstractHero
{
	virtual void showAttribute()
	{
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
	virtual void upAttribute() = 0;

private:
	AbstractHero *mHero;
};

class SuperHero : AbstractEquipmentHero
{
public:
	SuperHero(AbstractHero *hero) : AbstractEquipmentHero(hero)
	{
		HP = mHero->HP + 100
	}
	virtual void showAttribute()
	{

	}
	virtual void upAttribute()
	{

	}

private:
	AbstractHero * mHero;
};