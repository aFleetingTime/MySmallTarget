#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout.unsetf(ios::dec);		//卸载默认输出形式
	cout.setf(ios::hex);		//设置为十六进制输出
	cout << 156 << endl;		//输出结果9c
	cout.setf(ios::showbase);	//输出形式为十六进制时以0x开头，八进制以0开头
	cout << 156 << endl;

	cout.width(10);				//设置每次输出的字符数量（位宽），不够自动以fill函数所设置的符号填充(默认右对齐，且以空格填充)
	cout << 50 << endl;			//      0x32
	cout.width(10);				//width设置的宽度仅单次有效
	cout.fill('+');				//指定格式化填充的字符
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