#include "SocketProducerNew.h"

SocketProducerNew::SocketProducerNew(const char *ip, int port)
{
	if (ip == nullptr || port < 0)
	{
		this->ip = nullptr;
		this->port = -1;
		return;
	}
	this->ip = new char[strlen(ip) + 1];
	strcpy(this->ip, ip);
	this->port = port;
}

SocketProducerNew::~SocketProducerNew()
{
	if (buf != nullptr)
	{
		delete buf;
		buf = nullptr;
	}
	if (ip != nullptr)
	{
		delete ip;
		ip = nullptr;
	}
}

int SocketProducerNew::socketInit()
{
	if (ip == nullptr || port < 0)
		return -1;

	this->buf = nullptr;
	this->buflen = 0;
	return 0;
}

int SocketProducerNew::socketSend(unsigned char * buf, int buflen)
{
	if (buf == nullptr || buflen <= 0)
	{
		return -1;
	}
	this->buflen = buflen;
	this->buf = new unsigned char[buflen];
	if (buf == nullptr)
		return -2;
	memcpy(this->buf, buf, buflen);
	std::cout << "成功向IP:" << this->ip << " " << "端口:" << this->port << "发送数据" << std::endl;
	return 0;
}

int SocketProducerNew::socketRev(unsigned char * buf, int * buflen)
{
	if (buf == nullptr || buflen == nullptr)
		return -1;
	*buflen = this->buflen;
	memcpy(buf, this->buf, this->buflen);
	std::cout << "收到来自IP:" << this->ip << " " << "端口:" << this->port << "发送的数据" << std::endl;
	return 0;
}

int SocketProducerNew::socketDestory()
{
	SocketProducerNew::~SocketProducerNew();
	return 0;
}
