#pragma once
#include "DMServiceHandle.h"
#include "ace/Task_T.h"
#include "ace/Synch_Traits.h"
#include "ProxyRouter.h"
#include "DMMessage.h"

class ProxyServiceHandle : public DMServiceHandle
{
public:
	//主要是处理从消息服务器过来的维护、心跳、添加/删除proxy的消息
	virtual void handle(const AMQP::Message &message) override;

	//在连接上接收accountid，返回一个proxyserver的host
	virtual int handle_input(ACE_HANDLE fd = ACE_INVALID_HANDLE) override;

    //重写实现。需要绑定到不同的reactor上面
	virtual int open(void *acceptor_or_connector = 0) override;

private:
	bool recv_client_data(DMMessage &msg);

    void user_connect(ACE_HANDLE fd, short uid);

    void user_disconnect(ACE_HANDLE fd);

    void user_activate(DMMessage &msg);

    void maintain_service(short cmd);
};
