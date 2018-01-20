#pragma once
#include "EncryptProtocol.h"
#include "des.h"

class EncryptProducer : public EncryptProtocol
{
public:
	EncryptProducer();
	virtual ~EncryptProducer();
	virtual int EncData(unsigned char *pla, int plaLen, unsigned char *cip, int *cipLen);
	virtual int DecData(unsigned char *cip, int cipLen, unsigned char *pla, int *plaLen);
};

