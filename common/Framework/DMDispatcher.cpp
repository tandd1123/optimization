#include "DMDispatcher.h"
#include "DMAcceptor.h"
#include "DMMultiTask.h"

DMDispatcher::DMDispatcher()
{
    _msg_queue = DMMessageQueue::instance();    
    _tcp_state = DMJsonCfg::instance()->GetItemInt("service_info", "service_tcp");
}

void DMDispatcher::init()
{
    _msg_queue->register_dispatcher(this);
    _msg_queue->init();
}

//完成头解析和连接管理
DM_INT DMDispatcher::handle_input(ACE_HANDLE fd)
{
    DMMessage* client_message = new DMMessage;
 
    if (!_router.receive(fd, *client_message))
    {
        DM_LOG(DM_INFO,"receive false");
        return -1;
    }

    DMTask::instance()->put_msg(client_message);
    //内存释放?
    //delete client_message;
    return _tcp_state;
}

DM_INT DMDispatcher::handle_input(const AMQP::Message &message)
{
    DMMessage* server_message = new DMMessage;;
    
    if (!_router.receive(*server_message, message))
    {
        return -1;
    }

    DMTask::instance()->put_msg(server_message);
    
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

