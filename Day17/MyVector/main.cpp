#include <iostream>
#include <string>
#include <vector>

#include "MyVector.h"

using namespace std;

int main()
{
	cout << "����:" << endl;
	MyVector<int> vec;
	for (int i = 1; i <= 10; ++i)
		vec.push_back(i);

	for (int &i : vec)
	{
		cout << i << ' ' << endl;
	}
	cout << endl;

	//vec.printArray();

	//cout << "����:" << endl;
	//vec.insert(vec.begin() + 5, 666);
	//vec.printArray();

	//cout << "ɾ��:" << endl;
	//vec.erase(vec.begin() + 5);
	//vec.printArray();

	//cout << "���:" << endl;
	//vec.clear();
	//vec.printArray();

	//cout << "���:" << endl;
	//vec.push_back(123);
	//vec.printArray();

	//cout << "at" << endl;
	//cout << vec.at(0) << endl;

	//cout << "front" << endl;
	//cout << vec.front() << endl;

	//cout << "back" << endl;
	//cout << vec.back() << endl;

	//cout << "pop" << endl;
	//vec.pop_back();
	//vec.printArray();


	system("pause");
	return 0;
}