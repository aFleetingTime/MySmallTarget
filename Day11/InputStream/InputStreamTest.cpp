#include <iostream>

using namespace std;

int main()
{
	cin.putback('a');	//��һ���ַ�д����׼���뻺����
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