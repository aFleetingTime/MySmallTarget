#include <iostream>
#include <string>

#include <vector>

using namespace std;

void test2(int a)
{
	cout << "test2" << endl;
}
void test1()
{
	cout << "test1" << endl;
}
int main()
{
	void(*d)(void) = (void(*)(void))test2;
	d();
	int a = 0;
	int *p = &a + 5;
	int *s = p + 10;
	cout << s - p << endl;
	cout << p - s << endl;
	cout << sizeof(vector<int>::iterator) << endl;

	system("pause");
	return 0;
}