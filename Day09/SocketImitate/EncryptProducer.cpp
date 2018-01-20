#include "EncryptProducer.h"



EncryptProducer::EncryptProducer()
{
}


EncryptProducer::~EncryptProducer()
{
}

int EncryptProducer::EncData(unsigned char * pla, int plaLen, unsigned char * cip, int * cipLen)
{
	int retu = 0;
	if (retu = DesEnc(pla, plaLen, cip, cipLen))
		return retu;
	return 0;
}

int EncryptProducer::DecData(unsigned char * cip, int cipLen, unsigned char * pla, int * plaLen)
{
	int retu = 0;
	if (retu = DesDec(cip, cipLen, pla, plaLen))
		return retu;
	return 0;
}
