#include <iostream>
#include <string>
#include <vector>

#include "MyVector.h"

using namespace std;

int main()
{
	cout << "构造:" << endl;
	MyVector<int> vec(10, 0);
	vec.printArray();

	cout << "插入:" << endl;
	vec.insert(vec.begin() + 5, 666);
	vec.printArray();

	cout << "删除:" << endl;
	vec.erase(vec.begin() + 5);
	vec.printArray();

	cout << "清空:" << endl;
	vec.clear();
	vec.printArray();

	cout << "添加:" << endl;
	vec.push_back(123);
	vec.printArray();

	cout << "at" << endl;
	cout << vec.at(0) << endl;

	cout << "front" << endl;
	cout << vec.front() << endl;

	cout << "back" << endl;
	cout << vec.back() << endl;

	cout << "pop" << endl;
	vec.pop_back();
	vec.printArray();


	system("pause");
	return 0;
}