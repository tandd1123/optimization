#pragma once
#include "DMaker.h"

class DMMessageParser
{
public:
	    
	DMMessageHead parse(DM_CHAR* begin);
    
    DM_INT32 parse(DMMessage& out, const AMQP::Message &in);
    
	DM_INT32 pack(DMMessage& mesg, DM_CHAR* buf);

protected:
private:
	template<typename T> void DMGetBitData(DM_CHAR *src,T *dsc,DM_INT32 bit_s,DM_INT32 bit_e);

    template<typename T> void DMGetBitData(const DM_CHAR *src, T *dsc, DM_INT32 bit_s, DM_INT32 bit_e);
};
