#include "DMMessageParser.h"

DMMessageHead DMMessageParser::parse(DM_CHAR * begin)
{
	DMMessageHead msg_head;

	DMGetBitData(begin,&msg_head.msg_uid,0,32);
	DMGetBitData(begin,&msg_head.msg_cmd,32,64);
	DMGetBitData(begin,&msg_head.length,64,96);
	DMGetBitData(begin,&msg_head.reserved,96,128);

	return msg_head;
}

DM_BOOL DMMessageParser::parse(DMMessage& out, const AMQP::Message &in)
{
	DMMessageHead msg_head;
    
	if (in.bodySize() < HEAD_CHAR_LEN)
	{
		return FALSE;
	}

	const DM_CHAR* msg = in.body();

	DMGetBitData(msg,&msg_head.msg_uid,0,32);
	DMGetBitData(msg,&msg_head.msg_cmd,32,64);
	DMGetBitData(msg,&msg_head.length,64,96);
	DMGetBitData(msg,&msg_head.reserved,96,128);
    
	const DM_CHAR *body = msg + HEAD_CHAR_LEN;
    //注意内存大小保护
	DM_NEW(out.body, in.bodySize() - HEAD_CHAR_LEN);
	memcpy(out.body,body,(in.bodySize() - HEAD_CHAR_LEN));

    out.head = msg_head;

	return TRUE;
}

template <typename T>
void DMMessageParser::DMGetBitData(DM_CHAR *src,T *dsc,DM_UINT8 bit_s,DM_UINT8 bit_e)
{
	DM_CHAR *head_info = src;  //头地址
	short bit_info = 0x0;   //结果数据

	for (DM_INT32 i = 0; i < HEAD_CHAR_LEN; ++i)  //16 * 8 = 128
	{     
		bit_info = bit_info | (*(head_info++) & 0xFF);    //只取8位防止高位为1编译器转32位做取反操作
        
        if (bit_s == (CHAR_BIT_LEN * i))
        { 
    		break;
        }   
        
        bit_info = 0x0;
	}

    if (CHAR_BIT_LEN != (bit_e - bit_s))    //取16位
    {
        bit_info = bit_info | ((*head_info & 0xFF) << CHAR_BIT_LEN);
    }
        
	*dsc =  *dsc | bit_info;
}

template <typename T>
void DMMessageParser::DMGetBitData(const DM_CHAR *src, T *dsc, DM_UINT8 bit_s, DM_UINT8 bit_e)
{
	const DM_CHAR *head_info = src;
	short bit_info = 0x0;

	for (DM_INT32 i = 0; i < HEAD_CHAR_LEN; ++i)
	{     
		bit_info = bit_info | (*(head_info++) & 0xFF);
        
        if (bit_s == (CHAR_BIT_LEN * i))
        { 
    		break;
        }   
                
        bit_info = 0x0;
	}

    if (CHAR_BIT_LEN != (bit_e - bit_s))
    {
        bit_info = bit_info | ((*head_info & 0xFF) << CHAR_BIT_LEN);
    }
        
	*dsc =  *dsc | bit_info;
}

DM_BOOL DMMessageParser::pack(DMMessage& mesg, DM_CHAR* buf)
{
	DMMessageHead head;

    head = mesg.head;

	memcpy(buf, &head,sizeof(head));
	memcpy(buf + sizeof(head), mesg.body, head.length);

	return TRUE;
}

