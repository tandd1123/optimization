#pragma once
#include "DMaker.h"

class DMMessageEvent : public AMQP::TcpHandler : public ACE_Event_Handler
{
public:
    
	virtual void onConnected(AMQP::TcpConnection *connection);


	virtual void onError(AMQP::TcpConnection *connection, const DM_CHAR *message);

	
	virtual void onClosed(AMQP::TcpConnection *connection);

	
	virtual void monitor(AMQP::TcpConnection *connection, DM_UINT fd, DM_UINT flags);


	virtual DM_UINT handle_input(ACE_HANDLE fd);


	virtual DM_UINT handle_output(ACE_HANDLE fd = ACE_INVALID_HANDLE);
    
protected:
    
	ACE_Event_Handler* _handler;
    
	AMQP::TcpConnection *_connection;
};
