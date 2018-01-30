#include <iostream>
#include <string>

#include <vector>

using namespace std;

class A
{
public:
	A(int a)
	{

	}
};

int main()
{

	int a = 0;
	int *p = &a + 5;
	int *s = p + 10;
	cout << s - p << endl;
	cout << p - s << endl;
	cout << sizeof(vector<int>::iterator) << endl;

	system("pause");
	return 0;
}