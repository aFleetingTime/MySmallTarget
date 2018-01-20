#include "SchemaClass.h"



SchemaClass::SchemaClass(SocketProtocol *socket, EncryptProtocol * encrypt)
{
	this->socket = socket;
	this->encrypt = encrypt;
}


SchemaClass::~SchemaClass()
{
	if (this->socket != nullptr)
	{
		delete this->socket;
		this->socket = nullptr;
	}
	if (this->encrypt != nullptr)
	{
		delete this->encrypt;
		this->encrypt = nullptr;
	}
}

int SchemaClass::socketSendAndRev(unsigned char *inBuf, int inLen, unsigned char *outBuf, int *outLen)
{
	if (inBuf == nullptr || inLen <= 0 || outBuf == nullptr || outLen == nullptr)
		return -1;

	int retu = 0;
	unsigned char outBufCip[4096]{}, inBufCip[4096]{};
	int plaLen = 0, cipLen = 0;

	retu = this->socket->socketInit();
	if (retu)
		goto End;

	retu = encrypt->EncData(inBuf, inLen, inBufCip, &cipLen);
	if (retu)
		goto End;
	std::cout << "数据已加密..." << std::endl;

	retu = this->socket->socketSend(inBufCip, cipLen);
	if (retu)
		goto End;

	retu = this->socket->socketRev(outBufCip, &plaLen);
	if (retu)
		goto End;

	retu = encrypt->DecData(outBufCip, plaLen, outBuf, outLen);
	if (retu)
		goto End;
	std::cout << "数据已解密..." << std::endl;

	retu = this->socket->socketDestory();
	if (retu)
		goto End;

End:
	return retu;
}
