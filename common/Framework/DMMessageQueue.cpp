#include "DMMessageQueue.h"
#include "ace/Reactor.h"
#include "DMService.h"
#include <ace/Log_Msg.h>
#include <DMServiceMap.h>
#include <map>

DMMessageQueue* DMMessageQueue::_instance = nullptr;

DM_INT32 DMMessageQueue::init(string host,DM_INT32 port, string username, string userpasswd,string serviceName)
{
	// create an instance of your own tcp handler
	_handle = DM_NEW() DMMessageEvent();

	// address of the server
	AMQP::Address address(host, port,AMQP::Login(username,userpasswd),"/");

	// create a AMQP connection object
	_connection = DM_NEW() AMQP::TcpConnection(_handle, address);

	// and create a channel
	_channel = DM_NEW() AMQP::TcpChannel(_connection);

    //get service id
    map<string, DM_INT32> service_map = DMServiceMap::instance()->service_map;
    _service_id = service_map[serviceName];

	auto receiveMessageCallback = [=](const AMQP::Message &message,
		uDM_INT3264_t deliveryTag,
		DM_BOOL redelivered)
	{
		_dispatcher->receive_app_msg(message);
		_channel->ack(deliveryTag); //ack rabbitmq-server
	};

	AMQP::QueueCallback callback =
		[=](const string &queue_name, DM_INT32 msgcount, DM_INT32 consumercount)
	{
	    //exchange、targetqueue、routingkey,生产队列，三种exchange绑定所有队列，路由键即队列名
		_channel->bindQueue("fanout", queue_name, queue_name);
        
		_channel->bindQueue("direct", queue_name, queue_name);
        
		_channel->bindQueue("topic", queue_name, queue_name);

        //消费队列,只消费本server对应的队列
	    map<DM_INT32, vector<string>> queue_map = DMServiceMap::instance()->queue_map;
        vector<string> consume_queue = queue_map[_service_id];

        for (unsigned DM_INT32 i = 0; i < consume_queue.size(); ++i)
        {
            if (consume_queue[i] == queue_name)
            {
                _channel->consume(queue_name, AMQP::durable).onReceived(receiveMessageCallback);
            }
        }
        
	};

	AMQP::SuccessCallback success = [this, callback]()
	{
	    map<DM_INT32, vector<string>> queue_map = DMServiceMap::instance()->queue_map;
        map<DM_INT32, vector<string>>::iterator svr_it = queue_map.begin();

        for (; svr_it != queue_map.end(); ++svr_it)
        {
            vector<string> queue = svr_it->second;
            for (unsigned DM_INT32 i = 0; i < queue.size(); ++i)
            {
                _channel->declareQueue(queue[i], AMQP::durable).onSuccess(callback);
            }
        }  
        
	};

	//定义三个类型的exchange，根据参数需要选择
	//直接转发到所有绑定的queue，跳过路由键匹配
	_channel->declareExchange("fanout", AMQP::fanout).onSuccess(success);
    //路由键完全匹配
	_channel->declareExchange("direct", AMQP::direct).onSuccess(success);
    //路由键通配
	_channel->declareExchange("topic", AMQP::topic).onSuccess(success);

	return 0;
}

void DMMessageQueue::publish(const string &exchange, const string &routingKey, const DM_CHAR *message, size_t size)
{
	_channel->publish(exchange, routingKey, message, size);
}

DM_INT32 DMMessageQueue::getQueueMsgCount(string queueName)
{
    DM_INT32 count = 0;
    AMQP::QueueCallback callback =
            [&](const string &queue_name, DM_INT32 msgcount, DM_INT32 consumercount)
    {
        count = msgcount;
    };

    _channel->declareQueue(queueName, AMQP::passive).onSuccess(callback);

    return count;
}

void DMMessageQueue::runEvents()
{
	ACE_Reactor::instance()->run_event_loop();
}

void DMMessageQueue::destroy()
{
	if (_handle)
	{
		DM_DELETE() _handle;
		_handle = nullptr;
	}

	if (_connection)
	{
		DM_DELETE() _connection;
		_connection = nullptr;
	}

	if (_channel)
	{
		DM_DELETE() _channel;
		_channel = nullptr;
	}

	if (_instance)
	{
		DM_DELETE() _instance;
		_instance = nullptr;
	}
}

DMMessageQueue::~DMMessageQueue()
{
	destroy();
}
