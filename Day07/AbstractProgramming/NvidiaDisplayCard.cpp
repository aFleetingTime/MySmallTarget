#include "NvidiaDisplayCard.h"



NvidiaDisplayCard::NvidiaDisplayCard(string model) : DisplayCard(model)
{
	cout << "显卡已安装... 型号:" << DisplayCard::model << endl;
}
void NvidiaDisplayCard::start()
{
	cout << "Nvidia 显卡 开始工作..." << endl;
}
void NvidiaDisplayCard::close()
{
	cout << "Nvidia 显卡 停止运行..." << endl;
}