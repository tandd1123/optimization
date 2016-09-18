#include "DMMessageEvent.h"

void DMMessageEvent::onConnected(AMQP::TcpConnection *connection)
{
    DM_LOG(DM_INFO,"Connected MQ success!");
}

void DMMessageEvent::onError(AMQP::TcpConnection *connection, const DM_CHAR *message)
{
    DM_LOG(DM_ERROR,"Connected MQ ERROR!");
}

void DMMessageEvent::onClosed(AMQP::TcpConnection *connection)
{
    DM_LOG(DM_ERROR,"MQ Connected closed!");
}

void DMMessageEvent::monitor(AMQP::TcpConnection *connection, DM_INT32 fd, DM_INT32 flags)
{	
    _connection = connection;
    //MQ的IO可能与client的IO存在冲突，所以分配在不同的反应器上
	ACE_Reactor::instance()->register_handler(fd, this, ACE_Event_Handler::READ_MASK/*|ACE_Event_Handler::WRITE_MASK*/);
}

DM_INT32 DMMessageEvent::handle_input(ACE_HANDLE fd)
{
	_connection->process(fd, AMQP::readable);
	return 0;
}

