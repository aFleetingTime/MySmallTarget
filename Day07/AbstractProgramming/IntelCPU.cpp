#include "IntelCPU.h"



IntelCPU::IntelCPU(string model) : CPU(model)
{
	cout << "CPU�Ѱ�װ... �ͺ�:" << CPU::model << endl;
}
void IntelCPU::start()
{
	cout << "Intel CPU ��ʼ��������..." << endl;
}
void IntelCPU::close()
{
	cout << "Intel CPU �ѹر�..." << endl;
}
