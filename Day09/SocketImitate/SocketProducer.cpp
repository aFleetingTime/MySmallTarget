#include "SocketProducer.h"



SocketProducer::SocketProducer()
{
}


SocketProducer::~SocketProducer()
{
	if (buf != nullptr)
	{
		delete buf;
		buf = nullptr;
	}
}

int SocketProducer::socketInit()
{
	this->buf = nullptr;
	this->buflen = 0;
	return 0;
}

int SocketProducer::socketSend(unsigned char * buf, int buflen)
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
	return 0;
}

int SocketProducer::socketRev(unsigned char * buf, int * buflen)
{
	if (buf == nullptr || buflen == nullptr)
		return -1;
	*buflen = this->buflen;
	memcpy(buf, this->buf, this->buflen);
	return 0;
}

int SocketProducer::socketDestory()
{
	SocketProducer::~SocketProducer();
	return 0;
}
