#include "KingstonMemory.h"



KingstonMemory::KingstonMemory(string model) : Memory(model)
{
	cout << "�ڴ����Ѱ�װ... �ͺ�:" << Memory::model << endl;
}
void KingstonMemory::start()
{
	cout << "Kingston �ڴ��� ��ʼ��д����..." << endl;
}
void KingstonMemory::close()
{
	cout << "Kingston �ڴ��� ֹͣ����..." << endl;
}