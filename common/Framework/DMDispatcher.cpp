#include "DMDispatcher.h"

DMDispatcher::DMDispatcher()
{
    _msg_queue = DMMessageQueue::instance();
    _msg_queue->register_dispatcher(this);
}

//完成头解析和连接管理
virtual int DMDispatcher::handle_input(ACE_HANDLE fd)
{
    _service
}

virtual int DMDispatcher::handle_input(const AMQP::Message &message)
{

}

