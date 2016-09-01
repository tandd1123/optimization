#pragma once
#include "DMaker.h"

class DMMessageParser
{
public:
	    
	DMMessageHead parse(char* begin);
    
    int parse(DMMessage& out, const AMQP::Message &in);
    
	int pack(DMMessage& mesg, char* buf);

protected:
private:
	template<typename T> void DMGetBitData(char *src,T *dsc,int bit_s,int bit_e);

    template<typename T> void DMGetBitData(const char *src, T *dsc, int bit_s, int bit_e);
};
