#include "DMMessageEvent.h"

void DMMessageEvent::onConnected(AMQP::TcpConnection *connection)
{

}

void DMMessageEvent::onError(AMQP::TcpConnection *connection, const DM_CHAR *message)
{

}

void DMMessageEvent::onClosed(AMQP::TcpConnection *connection)
{

}

void DMMessageEvent::monitor(AMQP::TcpConnection *connection, DM_INT32 fd, DM_INT32 flags)
{
	_handler = DM_NEW(DMMessageEvent(connection));
	ACE_Reactor::instance()->register_handler(fd, _handler, ACE_Event_Handler::READ_MASK/*|ACE_Event_Handler::WRITE_MASK*/);

}

DM_INT32 DMMessageEvent::handle_input(ACE_HANDLE fd)
{
	_connection->process(fd, AMQP::readable);
	return 0;
}

DM_INT32 DMMessageEvent::handle_output(ACE_HANDLE fd /*= ACE_INVALID_HANDLE*/)
{
	return 0;
}
