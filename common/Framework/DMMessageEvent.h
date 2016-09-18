//=============================================================================
/* 
*  File: DMMessageEvent.h
*
*  Author: bing
*
*  Date: 2016-09-01
*
*  Version: v2.0
*
*  Github/Mail: https://github.com/binchen-china    <563853086@qq.com>
*
*  Note:
*/
//=============================================================================

#pragma once
#include "DMaker.h"

class DMMessageEvent : public AMQP::TcpHandler, public ACE_Event_Handler
{
public:
    
	virtual void onConnected(AMQP::TcpConnection *connection);


	virtual void onError(AMQP::TcpConnection *connection, const DM_CHAR *message);

	
	virtual void onClosed(AMQP::TcpConnection *connection);

	
	virtual void monitor(AMQP::TcpConnection *connection, DM_INT fd, DM_INT flags);


	virtual DM_INT handle_input(ACE_HANDLE fd);
 
protected:
    
	ACE_Event_Handler* _handler;
    
	AMQP::TcpConnection *_connection;
};
