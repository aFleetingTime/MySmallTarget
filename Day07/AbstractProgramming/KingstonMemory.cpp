#include "KingstonMemory.h"



KingstonMemory::KingstonMemory(string model) : Memory(model)
{
	cout << "内存条已安装... 型号:" << Memory::model << endl;
}
void KingstonMemory::start()
{
	cout << "Kingston 内存条 开始读写数据..." << endl;
}
void KingstonMemory::close()
{
	cout << "Kingston 内存条 停止运行..." << endl;
}