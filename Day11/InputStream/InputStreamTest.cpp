#include <iostream>

using namespace std;

int main()
{
	cin.putback('a');	//将一个字符写至标准输入缓冲区
	cout << static_cast<char>(cin.get()) << endl;

	//char ch;
	//cin.get(ch);
	//cout << ch << endl;
	//cin.ignore(INT_MAX, '\n');
	//cin.get(ch);
	//cout << ch << endl;

	system("pause");
	return 0;
}