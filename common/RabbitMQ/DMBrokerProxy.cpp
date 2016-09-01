#include "DMBrokerProxy.h"
#include "ace/Reactor.h"
#include "DMService.h"
#include <ace/Log_Msg.h>
#include <DMServiceMap.h>
#include <map>
extern DMService* GetService();

DMBrokerProxy* DMBrokerProxy::_instance = NULL;

int DMBrokerProxy::init(std::string host,int port, std::string username, std::string userpasswd,std::string serviceName)
{
	// create an instance of your own tcp handler
	_handle = new DMBrokerMessageHandle();

	// address of the server
	AMQP::Address address(host, port,AMQP::Login(username,userpasswd),"/");

	// create a AMQP connection object
	_connection = new AMQP::TcpConnection(_handle, address);

	// and create a channel
	_channel = new AMQP::TcpChannel(_connection);

    //get service id
    std::map<std::string, int> service_map = DMServiceMap::instance()->service_map;
    _service_id = service_map[serviceName];

	auto receiveMessageCallback = [=](const AMQP::Message &message,
		uint64_t deliveryTag,
		bool redelivered)
	{
		GetService()->receive(message);
		_channel->ack(deliveryTag); //ack rabbitmq-server
	};

	AMQP::QueueCallback callback =
		[=](const std::string &queue_name, int msgcount, int consumercount)
	{
	    //exchange、targetqueue、routingkey,生产队列，三种exchange绑定所有队列，路由键即队列名
		_channel->bindQueue("fanout", queue_name, queue_name);
        
		_channel->bindQueue("direct", queue_name, queue_name);
        
		_channel->bindQueue("topic", queue_name, queue_name);

        //消费队列,只消费本server对应的队列
	    std::map<int, std::vector<std::string>> queue_map = DMServiceMap::instance()->queue_map;
        std::vector<std::string> consume_queue = queue_map[_service_id];

        for (unsigned int i = 0; i < consume_queue.size(); ++i)
        {
            if (consume_queue[i] == queue_name)
            {
                _channel->consume(queue_name, AMQP::durable).onReceived(receiveMessageCallback);
            }
        }
        
	};

	AMQP::SuccessCallback success = [this, callback]()
	{
	    std::map<int, std::vector<std::string>> queue_map = DMServiceMap::instance()->queue_map;
        std::map<int, std::vector<std::string>>::iterator svr_it = queue_map.begin();

        for (; svr_it != queue_map.end(); ++svr_it)
        {
            std::vector<std::string> queue = svr_it->second;
            for (unsigned int i = 0; i < queue.size(); ++i)
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

void DMBrokerProxy::publish(const std::string &exchange, const std::string &routingKey, const char *message, size_t size)
{
	_channel->publish(exchange, routingKey, message, size);
}

int DMBrokerProxy::getQueueMsgCount(std::string queueName)
{
    int count = 0;
    AMQP::QueueCallback callback =
            [&](const std::string &queue_name, int msgcount, int consumercount)
    {
        count = msgcount;
    };

    _channel->declareQueue(queueName, AMQP::passive).onSuccess(callback);

    return count;
}

void DMBrokerProxy::runEvents()
{
	ACE_Reactor::instance()->run_event_loop();
}

void DMBrokerProxy::destroy()
{
	if (_handle)
	{
		delete _handle;
		_handle = nullptr;
	}

	if (_connection)
	{
		delete _connection;
		_connection = nullptr;
	}

	if (_channel)
	{
		delete _channel;
		_channel = nullptr;
	}

	if (_instance)
	{
		delete _instance;
		_instance = nullptr;
	}
}

DMBrokerProxy::~DMBrokerProxy()
{
	destroy();
}
