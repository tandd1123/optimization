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
//底层封装消息接收和消息发送
class DMServiceImpl
{
public:
    DMServiceImpl();
    
    void init();
    
    void register_message_factory(DMMessageFactory* msg_factory);
    
private:   
    DMMessageFactory* _msg_factory;
    
    DMMultiTask* _task;
};

