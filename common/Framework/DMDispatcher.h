#pragma once
#include "DMaker.h"

class DMDispatcher : public ACE_Svc_Handler <ACE_SOCK_STREAM, ACE_MT_SYNCH>
{
public:
    //void register_service(DMService* pService){_service = pService};
private:
    
    int handle_input(const AMQP::Message &message);
    int handle_input(ACE_HANDLE fd);
    //DMService* _service;
    //DMMessageQueue* _msg_queue;
};

typedef ACE_Acceptor<DMDispatcher, ACE_SOCK_ACCEPTOR> DMAcceptor;
