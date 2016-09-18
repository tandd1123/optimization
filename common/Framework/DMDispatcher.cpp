#include "DMDispatcher.h"
#include "DMAcceptor.h"

DMDispatcher::DMDispatcher()
{
    _msg_queue = DMMessageQueue::instance();
    _msg_queue->register_dispatcher(this);
}

void DMDispatcher::init(DMService* pService)
{
    _service = pService;
    _msg_queue->init();
}

//完成头解析和连接管理
DM_INT DMDispatcher::handle_input(ACE_HANDLE fd)
{
    DM_TRACE("recive app message");
    DMMessage client_message;
    if (_router.receive(fd, client_message))
    {
        return -1;
    }

    //底层消息
    if (client_message.head.msg_cmd < SYSTEM_MSG)
    {
    
    }
    else
    {
        //上层消息
    }
    
    return -1;
}

DM_INT DMDispatcher::handle_input(const AMQP::Message &message)
{
    DM_TRACE("recive mq message");
    DMMessage server_message;
    
    if (_router.receive(server_message, message))
    {
        return -1;
    }
    
    //底层消息
    if (server_message.head.msg_cmd < SYSTEM_MSG)
    {
    
    }
    else
    {
        //上层消息
    }
    
    return 0;
}

DM_INT DMDispatcher::open(void *acceptor_or_connector)
{
	ACE_Reactor *pReactor = DMAcceptor::instance()->get_reactor();
	if ( -1 == get_handle() || nullptr == pReactor)
	{
		return -1;
	}

	if ( -1 == pReactor->register_handler(this, ACE_Event_Handler::READ_MASK /*| ACE_Event_Handler::WRITE_MASK*/))
    {
		return -1;
	}
    
	return 0;
}
