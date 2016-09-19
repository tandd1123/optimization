//=============================================================================
/* 
*  File: DMServiceImpl.h
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
#include "DMMessageFactory.h"
#include "DMMessage.h"

//底层封装消息接收和消息发送
class DMServiceImpl
{
public:    
    void init();
    
    void register_message_factory(DMMessageFactory* msg_factory);

    void register_cmd(DM_INT message_cmd, MESSAGE_CALLBACK_HANDLE func);

    static void message_task_callback(DMMessage& msg);
    
private:
    DMMessageFactory* _factory;
    map<DM_INT, MESSAGE_CALLBACK_HANDLE> _cmd_map;
};

