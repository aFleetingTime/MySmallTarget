#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include <iterator>
#include "SocketProducer.h"
#include "SocketProtocol.h"
#include "SchemaClass.h"
#include "SocketProducerNew.h"

using namespace std;


int main(int argv, char *argc[])
{
	//SchemaClass schema(new SocketProducer());
	SchemaClass schema(new SocketProducerNew("192.168.1.111", 6666));
	unsigned char inBuf[4096]{}, outBuf[4096]{};
	memcpy(inBuf ,"SocketTest", strlen("SocketTest") + 1);
	int inLen = strlen((char *)inBuf) + 1, outLen = 0;
	bool retu;
	if (retu = schema.socketSendAndRev(inBuf, inLen, outBuf, &outLen))
	{
		cout << "Socket发生错误,错误码:" << retu << endl;
		return retu;
	}
	cout << "接收数据:" << outBuf << endl << "长度:" << outLen << endl;
	//SocketProtocol socket = new SocketProducer;


	system("pause");
	return 0;
}