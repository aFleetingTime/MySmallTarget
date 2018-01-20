#pragma once
class EncryptProtocol
{
public:
	EncryptProtocol();
	virtual ~EncryptProtocol();
	virtual int EncData(unsigned char *pla, int plaLen, unsigned char *cip, int *cipLen) = 0;
	virtual int DecData(unsigned char *cip, int cipLen, unsigned char *pla, int *plaLen) = 0;
};

