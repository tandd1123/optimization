//=============================================================================
/* 
*  File: DMDispatcher.h
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
#include "DMService.h"
#include "DMMessageQueue.h"

class DMDispatcher : public ACE_Svc_Handler <ACE_SOCK_STREAM, ACE_MT_SYNCH>
{
public:
    DMDispatcher();
    
    void init(DMService* pService);

    int handle_input(const AMQP::Message &message);
    
    int handle_input(ACE_HANDLE fd);
    
private:   

    DMService* _service;
    
    DMMessageQueue* _msg_queue;
};
