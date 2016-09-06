#pragma once
#include "DMaker.h"

//rabitmq服务器连接代理，供service的dispatch使用
class DMMessageQueue
{
public:
	static DMMessageQueue* getInstance()
	{
		if (nullptr == _instance)
		{
			_instance = DM_NEW(*_instance, sizeof(DMMessageQueue));
		}
		return _instance;
	}
    //依据配置尝试创建所有队列，取消svrid入参

    //void register_dispatcher(DMDispatcher* pDispatcher){_dispatcher = pDispatcher};
    
	DM_BOOL init(string host, DM_UINT16 port, string username,string userpasswd,string serviceName);

	void publish(const string &exchange, const string &routingKey, const DM_CHAR *message, size_t size);

    DM_UINT getQueueMsgCount(string queueName);

    void runEvents();

	void destroy();

protected:
	DMMessageQueue(){};
	virtual ~DMMessageQueue();
    
private:
    DM_UINT8 _service_id;
    
	DMMessageEvent* _handle;

    DMDispatcher* _dispatcher;
    
	AMQP::TcpChannel* _channel;
    
	AMQP::TcpConnection* _connection;
    
	static DMMessageQueue *_instance;
};
