#include <iostream>
#include <stdexcept>
#include <fiostream>

using namespace std;

class MyOutOfRange : public out_of_range
{
public:
	MyOutOfRange(const char *info, int age) : out_of_range(info)
	{
		errorAge = age;
	}
	const char* what() const
	{
		cout << errorAge << "�ꣿ";
		return out_of_range::what();
	}
	~MyOutOfRange()
	{
		cout << "~MyOutOfRange()" << endl;
	}
private:
	int errorAge;
};

void Test(int age)
{
	if (age > 150)
		throw new MyOutOfRange("��������ģ�", age);
	else if(age < 0)
		throw new MyOutOfRange("?????????", age);
	cout << "û���쳣����" << endl;
}

int main()
{
	try
	{
		cout << "����:";
		int age;
		cin >> age;
		Test(age);
	}
	catch (exception *e)
	{
		cout << e->what() << endl;
		delete e;
	}

	system("pause");
	return 0;
}