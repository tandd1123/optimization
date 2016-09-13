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
    return -1;
}

DM_INT DMDispatcher::handle_input(const AMQP::Message &message)
{
    DM_TRACE("recive mq message");
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
