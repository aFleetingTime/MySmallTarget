#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AbstractBuilding
{
public:
	virtual void sell() = 0;
	virtual unsigned int getPrice() = 0;
	virtual string getQuality() = 0;

protected:
	unsigned int price;
	string quality;
	string name;
};

class BuildingA : public AbstractBuilding
{
public:
	BuildingA()
	{
		name = "BuildingA";
		quality = "��Ʒ��";
		price = 1000000;
	}
	virtual void sell()
	{
		cout << name << "�ɹ�����!" << " �۸�:" << price << endl;
	}
	virtual unsigned int getPrice()
	{
		return price;
	}
	virtual string getQuality()
	{
		return quality;
	}
};

class BuildingB : public AbstractBuilding
{
public:
	BuildingB()
	{
		name = "BuildingB";
		quality = "��Ʒ��";
		price = 500000;
	}
	virtual void sell()
	{
		cout << name << "�ɹ�����!" << " �۸�:" << price << endl;
	}
	virtual unsigned int getPrice()
	{
		return price;
	}
	virtual string getQuality()
	{
		return quality;
	}
};

class BuildingC : public AbstractBuilding
{
public:
	BuildingC()
	{
		name = "BuildingC";
		quality = "��Ʒ��";
		price = 100000;
	}
	virtual void sell()
	{
		cout << name << "�ɹ�����!" << " �۸�:" << price << endl;
	}
	virtual unsigned int getPrice()
	{
		return price;
	}
	virtual string getQuality()
	{
		return quality;
	}
};

class Intermediaries
{
public:
	Intermediaries()
	{
		building.push_back(new BuildingA());
		building.push_back(new BuildingB());
		building.push_back(new BuildingC());
	}
	~Intermediaries()
	{
		for (AbstractBuilding *bui : building)
		{
			if (bui != nullptr)
				delete bui;
		}
	}
	AbstractBuilding* findBuilding(string quality)
	{
		for (AbstractBuilding *bui : building)
		{
			if (bui->getQuality() == quality)
			{
				return bui;
			}
		}
		return nullptr;
	}

private:
	vector<AbstractBuilding*> building;
};

int main()
{
	Intermediaries in;
	AbstractBuilding *building = in.findBuilding("��Ʒ��");
	string n("���е�");
	string::iterator beg = n.begin(), End = beg;
	for (int i = 0; i < 3; ++i)
	{
		string temp(beg, End += 2);
		building = in.findBuilding(temp + "Ʒ��");
		if (building != nullptr)
		{
			building->sell();
		}
		else
		{
			cout << "û�з���Ҫ���¥��" << endl;
		}
		beg += 2;
	}

	system("pause");
	return 0;
}