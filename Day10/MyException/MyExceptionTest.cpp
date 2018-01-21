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
		cout << errorAge << "岁？";
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
		throw new MyOutOfRange("你是认真的？", age);
	else if(age < 0)
		throw new MyOutOfRange("?????????", age);
	cout << "没有异常发生" << endl;
}

int main()
{
	try
	{
		cout << "年龄:";
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