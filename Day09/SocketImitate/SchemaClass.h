#pragma once
#include "SocketProtocol.h"

class SchemaClass
{
public:
	SchemaClass(SocketProtocol *socket);
	~SchemaClass();
	int socketSendAndRev(unsigned char *inBuf, int inLen, unsigned char *outBuf, int *outLen);

private:
	SocketProtocol * socket;
};

