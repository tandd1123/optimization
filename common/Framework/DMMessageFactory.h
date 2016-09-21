//=============================================================================
/* 
*  File: DMMessageFactory.h
*
*  Author: bing
*
*  Date: 2016-09-01
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
#include "DMMultiTask.h"
#include "DMMessage.h"

//消息指定编解码类

class DMMessageFactory
{
public:
    
    virtual void init_cmd()=0;
  
    void register_cmd(DM_INT message_cmd, MESSAGE_CALLBACK_HANDLE func);

    MESSAGE_CALLBACK_HANDLE find_callback_handle(DM_INT cmd);

    template<class PROTO_NAME>
    DM_BOOL paser_proto_message(DM_CHAR* msg, PROTO_NAME& proto_msg, DM_INT msg_length);

    template<class PROTO_NAME>
    DM_BOOL pack_proto_message(DM_CHAR* msg, PROTO_NAME& proto_msg, DM_INT msg_length);
    
private:
    map<DM_INT, MESSAGE_CALLBACK_HANDLE> _cmd_map;
};

#include "DMMessageFactory.inl"

