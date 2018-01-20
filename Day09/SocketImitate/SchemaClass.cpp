#include "SchemaClass.h"



SchemaClass::SchemaClass(SocketProtocol *socket)
{
	this->socket = socket;
}


SchemaClass::~SchemaClass()
{
	if (this->socket != nullptr)
	{
		delete this->socket;
		this->socket = nullptr;
	}
}

int SchemaClass::socketSendAndRev(unsigned char *inBuf, int inLen, unsigned char *outBuf, int *outLen)
{
	if (inBuf == nullptr || inLen <= 0 || outBuf == nullptr || outLen == nullptr)
		return -1;

	int retu = 0;

	retu = this->socket->socketInit();
	if (retu != 0)
		goto End;

	retu = this->socket->socketSend(inBuf, inLen);
	if (retu != 0)
		goto End;

	retu = this->socket->socketRev(outBuf, &(*outLen));
	if (retu != 0)
		goto End;

	retu = this->socket->socketDestory();
	if (retu != 0)
		goto End;

End:
	return retu;
}
