#include "DMMessageParser.h"

DMMessageHead DMMessageParser::parse(DM_CHAR * begin)
{
	DMMessageHead msg_head;

	DMGetBitData(begin,&msg_head.msg_id,0,16);
	DMGetBitData(begin,&msg_head.user_id,16,32);
	DMGetBitData(begin,&msg_head.msg_cmd,32,48);
	DMGetBitData(begin,&msg_head.length,48,64);
	DMGetBitData(begin,&msg_head.from,64,72);
	DMGetBitData(begin,&msg_head.to,72,80);
	DMGetBitData(begin,&msg_head.cluster_id,80,88);
	DMGetBitData(begin,&msg_head.node_id,88,96);
	DMGetBitData(begin,&msg_head.wait_time,96,104);
	DMGetBitData(begin,&msg_head.flag,104,112);

	return msg_head;
}

DM_INT32 DMMessageParser::parse(DMMessage& out, const AMQP::Message &in)
{
	DMMessageHead msg_head;
    
	if (in.bodySize() < HEAD_DM_CHAR_LEN)
	{
		return 0;
	}

	const DM_CHAR* msg = in.body();

	DMGetBitData(msg,&msg_head.msg_id,0,16);
	DMGetBitData(msg,&msg_head.user_id,16,32);
	DMGetBitData(msg,&msg_head.msg_cmd,32,48);
	DMGetBitData(msg,&msg_head.length,48,64);
	DMGetBitData(msg,&msg_head.from,64,72);
	DMGetBitData(msg,&msg_head.to,72,80);
	DMGetBitData(msg,&msg_head.cluster_id,80,88);
	DMGetBitData(msg,&msg_head.node_id,88,96);
	DMGetBitData(msg,&msg_head.wait_time,96,104);
	DMGetBitData(msg,&msg_head.flag,104,112);
    
	const DM_CHAR *body = msg + HEAD_DM_CHAR_LEN;
	out.body = DM_NEW() DM_CHAR[in.bodySize() - HEAD_DM_CHAR_LEN];
	memcpy(out.body,body,(in.bodySize() - HEAD_DM_CHAR_LEN));

	return 1;
}

template <typename T>
void DMMessageParser::DMGetBitData(DM_CHAR *src,T *dsc,DM_INT32 bit_s,DM_INT32 bit_e)
{
	DM_CHAR *head_info = src;  //头地址
	short bit_info = 0x0;   //结果数据

	for (DM_INT32 i = 0; i < HEAD_DM_CHAR_LEN; ++i)  //16 * 8 = 128
	{     
		bit_info = bit_info | (*(head_info++) & 0xFF);    //只取8位防止高位为1编译器转32位做取反操作
        
        if (bit_s == (DM_CHAR_BIT_LEN * i))
        { 
    		break;
        }   
        
        bit_info = 0x0;
	}

    if (DM_CHAR_BIT_LEN != (bit_e - bit_s))    //取16位
    {
        bit_info = bit_info | ((*head_info & 0xFF) << DM_CHAR_BIT_LEN);
    }
        
	*dsc =  *dsc | bit_info;
}

template <typename T>
void DMMessageParser::DMGetBitData(const DM_CHAR *src, T *dsc, DM_INT32 bit_s, DM_INT32 bit_e)
{
	const DM_CHAR *head_info = src;
	short bit_info = 0x0;

	for (DM_INT32 i = 0; i < HEAD_DM_CHAR_LEN; ++i)
	{     
		bit_info = bit_info | (*(head_info++) & 0xFF);
        
        if (bit_s == (DM_CHAR_BIT_LEN * i))
        { 
    		break;
        }   
                
        bit_info = 0x0;
	}

    if (DM_CHAR_BIT_LEN != (bit_e - bit_s))
    {
        bit_info = bit_info | ((*head_info & 0xFF) << DM_CHAR_BIT_LEN);
    }
        
	*dsc =  *dsc | bit_info;
}

DM_INT32 DMMessageParser::pack(DMMessage & mesg, DM_CHAR * buf)
{
	DMMessageHead head;

    head = mesg.head;

	memcpy(buf,&head,sizeof(head));
	memcpy(buf + sizeof(head),mesg.body,head.length);

	return 0;
}
