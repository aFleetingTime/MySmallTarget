#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout.unsetf(ios::dec);		//ж��Ĭ�������ʽ
	cout.setf(ios::hex);		//����Ϊʮ���������
	cout << 156 << endl;		//������9c
	cout.setf(ios::showbase);	//�����ʽΪʮ������ʱ��0x��ͷ���˽�����0��ͷ
	cout << 156 << endl;

	cout.width(10);				//����ÿ��������ַ�������λ���������Զ���fill���������õķ������(Ĭ���Ҷ��룬���Կո����)
	cout << 50 << endl;			//      0x32
	cout.width(10);				//width���õĿ�Ƚ�������Ч
	cout.fill('+');				//ָ����ʽ�������ַ�
	cout << 50 << endl;			//++++++0x32
	cout.setf(ios::left);
	cout.fill('+');
	cout.width(10);				//0x32++++++
	cout << 50 << endl;

	cout.unsetf(ios::hex);
	cout.unsetf(ios::showbase);
	cout << hex
		<< setiosflags(ios::left)
		<< setfill('=')
		<< setiosflags(ios::showbase)
		<< setw(12)
		<< 55
		<< endl;

	cout << 600 << endl;

	system("pause");
	return 0;
}