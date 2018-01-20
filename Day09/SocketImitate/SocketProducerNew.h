#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "SocketProducer.h"

class SocketProducerNew : public SocketProtocol
{
public:
	SocketProducerNew(const char *ip, int port);
	virtual ~SocketProducerNew();
	virtual int socketInit();
	virtual int socketSend(unsigned char *buf, int buflen);
	virtual int socketRev(unsigned char *buf, int *buflen);
	virtual int socketDestory();

private:
	char *ip;
	int port;
};

