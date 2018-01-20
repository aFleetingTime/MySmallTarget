#pragma once
#include <string.h>
#include "SocketProtocol.h"

class SocketProducer : public SocketProtocol
{
public:
	SocketProducer();
	virtual int socketInit();
	virtual int socketSend(unsigned char *buf, int buflen);
	virtual int socketRev(unsigned char *buf, int *buflen);
	virtual int socketDestory();

private:
	virtual ~SocketProducer();
};

