#pragma once
#include <iostream>
#include "SocketProtocol.h"
#include "EncryptProducer.h"
#include "EncryptProtocol.h"

class SchemaClass
{
public:
	SchemaClass(SocketProtocol *socket, EncryptProtocol * encrypt);
	~SchemaClass();
	int socketSendAndRev(unsigned char *inBuf, int inLen, unsigned char *outBuf, int *outLen);

private:
	SocketProtocol * socket;
	EncryptProtocol * encrypt;
};

