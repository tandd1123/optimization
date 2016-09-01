#pragma once
#include "DMaker.h"

class DMMessageParser
{
public:
	    
	DMMessageHead parse(DM_CHAR* begin);
    
    DM_BOOL parse(DMMessage& out, const AMQP::Message &in);
    
	DM_BOOL pack(DMMessage& mesg, DM_CHAR* buf);

protected:
private:
	template<typename T> void DMGetBitData(DM_CHAR *src,T *dsc,DM_UINT8 bit_s,DM_UINT8 bit_e);

    template<typename T> void DMGetBitData(const DM_CHAR *src, T *dsc, DM_UINT8 bit_s, DM_UINT8 bit_e);
};
