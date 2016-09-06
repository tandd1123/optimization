//=============================================================================
/* 
*  File: DMMessage.h
*
*  Author: bing
*
*  Date: 2016-08-12
*
*  Version: v2.0
*
*  Github/Mail: https://github.com/binchen-china    <563853086@qq.com>
*
*  Note:
*/
//=============================================================================

#pragma once
#include "DMaker.h"

/*-------------------------------------------------------------------------------
            msg head:
            --------------------------------------------------
            |       message id       |        user id        |
            --------------------------------------------------
            |       message cmd      |      body length      |
            --------------------------------------------------
            |    from    |     to    | cluster id | node id  |
            --------------------------------------------------
            | wait time  |    flag   |       reserve         |
            --------------------------------------------------

            flag:
                    bit 0:  req/resp
                    bit 1:  login
                    bit 2:  FE-service
                    bit 3:  notify
                    bit 4:  maDM_UINTain
                    bit 5:  heartbeat
                    bit 6:  timeout 
                    bit 7:  reserve
---------------------------------------------------------------------------------*/

enum msg_type   //公共维护消息 1000-1999
{
    ADD_PROXY_MSG = 1001,
    RMV_PROXY_MSG = 1002,
    STOP_SERVER   = 1003    
};

enum msg_flge    //公共flag标记
{
	REQUEST_MSG   = 0x01,
	RESPONS_MSG   = 0x02,

	LOGIN_MSG     = 0x04,
	HEARTBEAT_MSG = 0x08,
	SERVICE_MSG	  = 0x10,
	NOTIFY_MSG    = 0x20,
	MADM_UINT_MSG     = 0x40,

	MSG_MASK      = 0xFE,
};

enum DataSize
{
    HEAD_BIT_LEN = 128,
    HEAD_DM_CHAR_LEN = 16,
    DM_CHAR_BIT_LEN = 8
};


class DMMessageHead
{
public:
	DMMessageHead():msg_id(0),user_id(0),msg_cmd(0),length(0),
        from(0),to(0),cluster_id(0),node_id(0),wait_time(0),flag(0),reserved(0){};
	DM_UINT16 msg_id;
	DM_UINT16 user_id;
	DM_UINT16 msg_cmd;
	DM_UINT16 length;
	DM_CHAR from;
    DM_CHAR to;
    DM_CHAR cluster_id;
    DM_CHAR node_id;
    DM_CHAR wait_time;
    DM_CHAR flag;
    DM_UINT16 reserved;
    
    DMMessageHead& operator=(DMMessageHead other)
    {
        this->msg_id = other.msg_id;
        this->user_id = other.user_id;
        this->msg_cmd = other.msg_cmd;
        this->length = other.length;
        this->from = other.from;
        this->to = other.to;
        this->cluster_id = other.cluster_id;
        this->node_id = other.node_id;
        this->wait_time = other.wait_time;
        this->flag = other.flag;   
        this->reserved = other.reserved;
        
        return *this;
    }
};

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
        body = DMMemoryPool::instance()->require(body,size);
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
