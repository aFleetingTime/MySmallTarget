#include "NvidiaDisplayCard.h"



NvidiaDisplayCard::NvidiaDisplayCard(string model) : DisplayCard(model)
{
	cout << "�Կ��Ѱ�װ... �ͺ�:" << DisplayCard::model << endl;
}
void NvidiaDisplayCard::start()
{
	cout << "Nvidia �Կ� ��ʼ����..." << endl;
}
void NvidiaDisplayCard::close()
{
	cout << "Nvidia �Կ� ֹͣ����..." << endl;
}