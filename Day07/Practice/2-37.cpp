#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main(int argv, char *argc[])
{
	int a = 3, b = 4;
	decltype(a) c = a;		//int c = a(3);
	decltype(a = b) d = a;	//int &d = a(4);
	//decltype����ʵ�ʼ�����ʽ
	//a = 3, b = 4, c = 3, d = 3
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	//decltype��auto
	//��ͬ�㣺decltype��auto������ͨ������������ʽ����������������������ͣ���
	//����decltype�����������ã���auto�����ԡ�
	//	   ���decltype�ı��ʽ��const�������ã�decltypeͬ��������һ���������á���auto�ڳ�ʼ��ʱ���볣�����ã�auto�����������ý�����const

	system("pause");
	return 0;
}