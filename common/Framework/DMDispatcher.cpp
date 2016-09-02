#include "DMDispatcher.h"

//完成头解析和连接管理
virtual int DMDispatcher::handle_input(ACE_HANDLE fd)
{
    receive_app_msg();
}

virtual int DMDispatcher::handle_input(const AMQP::Message &message)
{
    receive_mq_msg();
}

