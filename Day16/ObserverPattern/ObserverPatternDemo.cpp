#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

class AbstractBoss;
class AbstractHero;

class AbstractHero
{
public:
	virtual void update(bool b) = 0;
	virtual bool bruise(unsigned ad) = 0;
	virtual void attackBoss() = 0;
	virtual void setTarget(AbstractBoss *boss) = 0;
	virtual string getName() = 0;
	virtual unsigned getAd() = 0;
	virtual bool isLive() = 0;
	virtual ~AbstractHero() {}
};

class AbstractBoss
{
public:
	virtual void addHero(AbstractHero *hero) = 0;
	virtual void removeHero(AbstractHero *hero) = 0;
	virtual void noticeHero(AbstractHero *hero) = 0;
	virtual void bruise(AbstractHero *hero) = 0;
	virtual void attack() = 0;
	virtual string getName() = 0;
	virtual bool isLive() = 0;
	virtual bool isTarget() = 0;
	virtual list<AbstractHero*>& getList() = 0;
};

class BlueHero : public AbstractHero
{
public:
	BlueHero(string name, int ad) : mAd(ad)
	{
		mName.assign(name);
		pTarget = nullptr;
		blood = 100;
	}
	~BlueHero()
	{
		cout << mName << "死亡" << endl;
	}
	virtual void update(bool b)
	{
		if (b)
			cout << "BlueHero:" << mName << "击杀了" << pTarget->getName() << "..." << endl;
		else
			cout << "BlueHero:" << mName << "助攻..." << endl;
		pTarget = nullptr;
	}
	virtual void attackBoss()
	{
		if (pTarget == nullptr)
		{
			cout << mName << "没有指定攻击目标" << endl;
			return;
		}
		cout << mName << "对" << pTarget->getName() << "造成" << mAd << "点伤害" << endl;
		pTarget->bruise(this);
	}
	virtual void setTarget(AbstractBoss *boss)
	{
		pTarget = boss;
	}
	virtual bool bruise(unsigned ad)
	{
		blood -= ad;
		cout << mName << "受到" << ad << "点伤害" << "剩余" << blood << endl;
		if (blood <= 0)
		{
			return true;
		}
		return false;
	}
	virtual string getName()
	{
		return mName;
	}
	virtual unsigned getAd()
	{
		return mAd;
	}
	virtual bool isLive()
	{
		return blood > 0;
	}

private:
	int blood;
	const unsigned mAd;
	string mName;
	AbstractBoss *pTarget;
};

class RedHero : public AbstractHero
{
public:
	RedHero(string name, int ad) : mAd(ad)
	{
		mName.assign(name);
		pTarget = nullptr;
		blood = 100;
	}
	~RedHero()
	{
		cout << mName << "死亡" << endl;
	}
	virtual void update(bool b)
	{
		if (b)
			cout << "RedHero:" << mName << "击杀了" << pTarget->getName() << "..." << endl;
		else
			cout << "RedHero:" << mName << "助攻..." << endl;
		pTarget = nullptr;
	}
	virtual void attackBoss()
	{
		if (pTarget == nullptr)
		{
			cout << mName << "没有指定攻击目标" << endl;
			return;
		}
		cout << mName << "对" << pTarget->getName() << "造成" << mAd << "点伤害" << endl;
		pTarget->bruise(this);
	}
	virtual void setTarget(AbstractBoss *boss)
	{
		pTarget = boss;
	}
	virtual bool bruise(unsigned ad)
	{
		blood -= ad;
		cout << mName << "受到" << ad << "点伤害" << "剩余" << blood << endl;
		if (blood <= 0)
		{
			return true;
		}
		return false;
	}
	virtual string getName()
	{
		return mName;
	}
	virtual unsigned getAd()
	{
		return mAd;
	}
	virtual bool isLive()
	{
		return blood > 0;
	}

private:
	int blood;
	const unsigned mAd;
	string mName;
	AbstractBoss *pTarget;
};

class Baron : public AbstractBoss
{
public:
	Baron(string name, unsigned ad) : mAd(ad)
	{
		mName.assign(name);
		blood = 1000;
	}
	virtual void addHero(AbstractHero *hero)
	{
		heroList.push_front(hero);
	}
	virtual void removeHero(AbstractHero *hero)
	{
		heroList.remove(hero);
	}
	virtual void noticeHero(AbstractHero *hero)
	{
		for (AbstractHero *bp : heroList)
		{
			if (bp == nullptr)
				continue;
			if(bp == hero)
				bp->update(true);
			else
				bp->update(false);
		}
	}
	virtual void bruise(AbstractHero *hero)
	{
		unsigned heroAd = hero->getAd();
		blood -= heroAd;
		cout << mName << "受到" << heroAd << "点伤害," << "剩余" << (blood < 0 ? 0 : blood) << endl;
		if (blood <= 0)
		{
			noticeHero(hero);
		}
	}
	virtual void attack()
	{
		if (!heroList.size())
		{
			cout << "没有可攻击的目标" << endl;
			return;
		}
		else if (blood <= 0)
			return;
		AbstractHero *targetHero = heroList.front();
		cout << mName << "对" << targetHero->getName() << "造成" << mAd << "点伤害" << endl;
		if (targetHero->bruise(mAd))
		{
			delete heroList.front();
			heroList.pop_front();
		}
	}
	virtual string getName()
	{
		return mName;
	}
	virtual bool isLive()
	{
		return blood > 0;
	}
	virtual bool isTarget()
	{
		return heroList.size();
	}
	virtual list<AbstractHero*>& getList()
	{
		return heroList;
	}

private:
	int blood;
	unsigned mAd;
	list<AbstractHero*> heroList;
	string mName;
};

#define RANDOM rand() % 30 + 10
#define RANDOM_HERO rand() % 5

void test()
{
	vector<AbstractHero*> blue;
	vector<AbstractHero*> red;
	AbstractBoss *boss = new Baron("Baron", 100);

	string str("ABCDE");
	string b("blue");
	string r("red");
	for (int i = 0; i != 5; ++i)
	{
		AbstractHero *hero = new BlueHero(b + str.at(i), RANDOM);
		hero->setTarget(boss);
		blue.push_back(hero);
		boss->addHero(hero);

		hero = new RedHero(r + str.at(i), RANDOM);
		red.push_back(hero);
		hero->setTarget(boss);
		red.back()->setTarget(boss);
		boss->addHero(hero);
	}
	list<AbstractHero*> &mlist = boss->getList();
	while (boss->isLive())
	{
		for (list<AbstractHero*>::iterator beg = mlist.begin(), End = mlist.end(); beg != End && boss->isLive(); ++beg)
		{
			if ((*beg)->isLive())
			{
				(*beg)->attackBoss();
				cout << "----------------------------" << endl;
			}
		}
		if (boss->isTarget() && boss->isLive())
		{
			boss->attack();
			cout << "----------------------------" << endl;
		}
		if (!mlist.size())
		{
			cout << "全部英雄阵亡" << endl;
			cout << "----------------------------" << endl;
			break;
		}
	}
	cout << "存活英雄:" << mlist.size() << endl;
	cout << "----------------------------" << endl;
}

int main()
{
	test();

	system("pause");
	return 0;
}