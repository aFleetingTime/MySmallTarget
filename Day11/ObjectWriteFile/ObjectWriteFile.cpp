#include <iostream>
#include <fstream>

using namespace std;

class Person
{
public:
	Person(const char *name, int age)
	{
		this->name_len = strlen(name);
		this->name = new char[name_len + 1];
		strcpy_s(this->name, name_len + 1, name);
		this->age = age;
	}
	Person()
	{
		this->name = nullptr;
		this->age = 0;
		this->name_len = 0;
	}
	~Person()
	{
		if (this->name != nullptr)
		{
			delete this->name;
			this->name = nullptr;
		}
	}
	void show()
	{
		cout << "Name:" << name << endl;
		cout << "Name_Len:" << name_len << endl;
		cout << "Age:" << age << endl;
	}
	char *name;
	int name_len;
	int age;
};

int main()
{
	const char *path = "F:/MyC++/MySmallTarget/Day11/ObjectWriteFile/Test/object.txt";

	Person p1[2]{ Person("Person1", 11), Person("Person2", 22) };

	ofstream ofs(path, ios::out);
	for (Person &p : p1)
	{
		ofs.write(reinterpret_cast<char*>(&p), sizeof(Person));
		ofs.write(p.name, strlen(p.name));
	}
	ofs.close();

	ifstream ifs(path, ios::in);
	Person p2[2];
	for (Person &p : p2)
	{
		ifs.read(reinterpret_cast<char*>(&p), sizeof(Person));
		p.name = new char[p.name_len + 1];
		ifs.read(p.name, p.name_len);
		p.name[p.name_len] = '\0';
		p.show();
	}
	ifs.close();

	system("pause");
	return 0;
}
