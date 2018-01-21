#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include <iterator>


using namespace std;

class Test1 {};
class Test2 {};
class Test3 : public Test2 {};

void static_cast_test()	//����ת���������͡����м̳й�ϵ��������ָ�롢����(�������Ͱ�ȫ���)
{
	//static_cast�ܹ�ת�������������ͣ�����ָ������ã������м̳й�ϵ�Ļ�����������֮���ת��������ָ������ã������ɻ�����������ת����,���޷�ת��û�м̳й�ϵ����
	int i = 0;
	double d = static_cast<double>(i);

	char c = 65;
	short s = static_cast<short>(c);

	Test2 *t2p = nullptr;
	Test3 *t3p = static_cast<Test3*>(t2p);

	//Test2 t2;		���ܴӻ�����������ת��
	//Test3 t3 = static_cast<Test3>(t2);

	//Test1 *t1;	����ת��û�м̳й�ϵ���࣬����ָ�������
	//Test2 *t2 = static_cast<Test2*>(t1);
}

void dynamic_cast_test() //����ת�����м̳й�ϵ�����ָ������ã��������Ͱ�ȫ��飬ת������ָ��ʱ���޷���static_cast����������ָ��ת��Ϊ������ָ�룩
{
	Test3 *t3 = nullptr;
	Test2 *t2 = t3;

	Test3 *t33 = nullptr;
	Test2 *t22 = dynamic_cast<Test2*>(t33);

	//Test3 t33;	ֻ��ת��ָ�����������
	//Test2 t22 = dynamic_cast<Test2>(t33);

	//Test2 *t2 = nullptr;	���ܴӻ�����������ת��
	//Test3 *t3 = dynamic_cast<Test3*>(t2);

	//int *i = 0;	����ת���������ͺ����ø�������
	//char *c = dynamic_cast<int*>(i);

	//Test2 t2;		���ܴӻ�����������ת��
	//Test3 t3 = dynamic_cast<Test3>(t2);
}

void const_cast_test() //���ڻ�ȡ��ӻ�ȡ��const���ָ�롢���á���������ָ��
{
	int i = 0;
	const int &ai = i;
	const_cast<int&>(ai) = 100;
	cout << i << endl;

	const int &ai1 = i;
	int &cai = const_cast<int&>(ai1);
	cai = 1000;
	cout << i << endl;

	const int &a = 0;
	const_cast<int&>(a) = 10;
	cout << a << endl;

	//const int &cai1 = const_cast<const int &>(cai);
	//cai1 = 10000;
}

void reinterpret_cast_test() //ǿ������ת�������Խ�ָ��(��������ָ��)������ת��Ϊ��������
{
	Test1 *t1 = nullptr;
	Test2 *t2 = reinterpret_cast<Test2*>(t1);

	int *ip = nullptr;
	string *sp = reinterpret_cast<string*>(ip);

	int *i = 0;
	char *s = reinterpret_cast<char*>(i);

	int *&ai = i;
	string *&&as = reinterpret_cast<string*>(ai);

	string *****&&ass = reinterpret_cast<string*****>(ai);
}

int main(int argv, char *argc[])
{
	static_cast_test();
	dynamic_cast_test();
	const_cast_test();
	reinterpret_cast_test();

	system("pause");
	return 0;
}