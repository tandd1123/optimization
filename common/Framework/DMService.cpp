#pragma once

#include "DMaker.h"
//底层封装消息接收和消息发送
class DMService// : public ACE_Task<ACE_MT_SYNCH>
{
public:
	virtual void handle(const AMQP::Message &message);
private:
};
