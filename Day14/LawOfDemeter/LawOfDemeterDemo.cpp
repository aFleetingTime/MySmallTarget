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
		quality = "高品质";
		price = 1000000;
	}
	virtual void sell()
	{
		cout << name << "成功出售!" << " 价格:" << price << endl;
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
		quality = "中品质";
		price = 500000;
	}
	virtual void sell()
	{
		cout << name << "成功出售!" << " 价格:" << price << endl;
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
		quality = "低品质";
		price = 100000;
	}
	virtual void sell()
	{
		cout << name << "成功出售!" << " 价格:" << price << endl;
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
	AbstractBuilding *building = in.findBuilding("高品质");
	string n("高中低");
	string::iterator beg = n.begin(), End = beg;
	for (int i = 0; i < 3; ++i)
	{
		string temp(beg, End += 2);
		building = in.findBuilding(temp + "品质");
		if (building != nullptr)
		{
			building->sell();
		}
		else
		{
			cout << "没有符合要求的楼盘" << endl;
		}
		beg += 2;
	}

	system("pause");
	return 0;
}