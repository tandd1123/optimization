#pragma once

#include "DMaker.h"
//底层封装消息接收和消息发送
class DMService : public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_MT_SYNCH>
{
public:
	virtual void handle(const AMQP::Message &message) = 0;
private:
};
