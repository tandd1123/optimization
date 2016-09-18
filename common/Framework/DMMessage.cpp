#pragma once
#include "DMaker.h"

/*-------------------------------------------------------------------------------
            msg head:
            --------------------------------------------------
            |                 Message id                     |
            --------------------------------------------------
            |                 Message length                 |
            --------------------------------------------------
            |                 Message cmd                    |
            --------------------------------------------------
            |                 Reserve                        |
            --------------------------------------------------
---------------------------------------------------------------------------------*/

enum msg_type   //公共维护消息 1000-1999
{
    ADD_PROXY_MSG = 1001,
    RMV_PROXY_MSG = 1002,
    STOP_SERVER   = 1003,   
    HEARTBEAT_MSG = 1004,
    SERVICE_MSG   = 1005
};

enum DataSize
{
    HEAD_BIT_LEN = sizeof(DM_INT32) * 4,
    HEAD_CHAR_LEN = 16,
    DM_CHAR_BIT_LEN = 8
};

#pragma pack (1)
class DMMessageHead
{
public:
	DMMessageHead():msg_id(0),length(0),msg_cmd(0),reserved(0){};
	DM_INT32 msg_id;
	DM_INT32 length;
	DM_INT32 msg_cmd;
	DM_INT32 reserved;
    
    DMMessageHead& operator=(DMMessageHead other)
    {
        this->msg_id = other.msg_id;
        this->length = other.length;
        this->msg_cmd = other.msg_cmd;
        this->reserved = other.reserved;
        
        return *this;
    }
};
#pragma pack ()

class DMMessage
{
public:
   	DMMessage()
	{
		body = nullptr;
	}
    
    ~DMMessage()
	{
		release_body_size();
	}
    
    void require_body_size(DM_UINT16 size)
    {
        _body_size = size;
        body = DMMemoryPool::instance()->require(size);
    }
    
    void release_body_size()
    {
        DMMemoryPool::instance()->release(_body_size,body);
    }
    
    DMMessage& operator=(DMMessage other)
    {
        this->head = other.head;
        this->body = other.body;
        this->_body_size = other._body_size;
        return *this;
    }
    
	DMMessageHead head;
	DM_CHAR* body;
private:
    DM_UINT16 _body_size;
}; 
