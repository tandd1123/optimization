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
#include "DMMessageQueue.h"
#include "DMMessageRouter.h"

class DMDispatcher : public ACE_Svc_Handler <ACE_SOCK_STREAM, ACE_MT_SYNCH>
{
public:
    DMDispatcher();
    
    void init();
    
    virtual int open(void *acceptor_or_connector = 0);

    DM_INT handle_input(const AMQP::Message &message);

private:  

    DM_INT handle_input(ACE_HANDLE fd);

    bool recv_client_data(DMMessage &msg);
       
private:

    DMMessageQueue* _msg_queue;
    
    DMMessageRouter _router;

    DM_INT _tcp_state;
};

