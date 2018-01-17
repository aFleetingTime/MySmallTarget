#include "IntelCPU.h"



IntelCPU::IntelCPU(string model) : CPU(model)
{
	cout << "CPU已安装... 型号:" << CPU::model << endl;
}
void IntelCPU::start()
{
	cout << "Intel CPU 开始处理数据..." << endl;
}
void IntelCPU::close()
{
	cout << "Intel CPU 已关闭..." << endl;
}
