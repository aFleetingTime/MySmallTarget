#pragma once
class SocketProtocol
{
public:
	SocketProtocol();
	virtual ~SocketProtocol();
	virtual int socketInit() = 0;
	virtual int socketSend(unsigned char *buf, int buflen) = 0;
	virtual int socketRev(unsigned char *buf, int *buflen) = 0;
	virtual int socketDestory() = 0;

protected:
	unsigned char *buf;
	unsigned int buflen;
};

