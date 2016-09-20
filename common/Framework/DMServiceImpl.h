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
enum send_dest
{
    DM_APP,
    DM_MQ
};

class DMServiceImpl
{
public:    
    void init();
    
    void register_message_factory(DMMessageFactory* msg_factory);

    void register_cmd(DM_INT message_cmd, MESSAGE_CALLBACK_HANDLE func);

    void send_message(DM_INT uid, DMMessage& msg, DM_INT dest);

    void publish_message(vector<DM_INT> uid, DMMessage& msg, DM_INT dest);

    static void message_task_callback(DMMessage& msg);

    virtual void init_cmd()=0;
    
private:
    void send_app_message(ACE_HANDLE fd, DMMessage& msg);
    
    void send_mq_message(DMMessage& msg);
    
private:
    DMMessageFactory* _factory;
    
    static map<DM_INT, MESSAGE_CALLBACK_HANDLE> _cmd_map;
};

