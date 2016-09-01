#include "ProxyServiceHandle.h"
#include "DMMessageParser.h"
#include "DMBrokerProxy.h"
#include "ReactorPool.h"
#include "ProxySessionMgr.h"
#include "ProxyService.h"
#include <ace/Log_Msg.h>

void ProxyServiceHandle::handle(const AMQP::Message &message)
{
	//server message
	ACE_DEBUG((LM_INFO,"proxy recevie msg,route to app or others\n"));

    //parse message
    DMMessageParser parser;
	DMMessage req_msg;
    
	if (!parser.parse(req_msg,message))
	{
		ACE_DEBUG((LM_INFO,"parse AMQP::Message error!\n"));
		return;
	}
		
	//pb decode
	switch (req_msg.head.flag & MSG_MASK)
	{
	case LOGIN_MSG: //login result from login server
		{         
            //激活session，首次登录用户带cluster、node数据做路由表维护
            if (true)   //if login success
            {
                user_activate(req_msg);
            }
            else
            {
                user_disconnect(req_msg.head.user_id);
            }
            
            ProxyService::instance()->dispatch(req_msg);
            
			break;
		}
	case HEARTBEAT_MSG:
		{
			break;
		}
	case SERVICE_MSG:
		{
            //服务间业务消息转发
            ProxyService::instance()->dispatch(req_msg);
            
			break;
		}
    case MAINT_MSG:
        {
            maintain_service(req_msg.head.msg_cmd);
        }
	}
}

int ProxyServiceHandle::handle_input(ACE_HANDLE fd /*= ACE_INVALID_HANDLE*/)
{
	ACE_DEBUG((LM_INFO,"app data, route to server!\n"));
	DMMessage client_msg;

	if (!recv_client_data(client_msg))
	{
		return -1;
	}

	switch (client_msg.head.flag & MSG_MASK)
	{
	case LOGIN_MSG:
		{         
            ACE_DEBUG((LM_INFO,"RECIVE LOGIN_MSG!\n"));
			user_connect(fd, client_msg.head.user_id);  
            
			DMMessage server_msg;
            server_msg = client_msg;
            
            ProxyService::instance()->dispatch(server_msg);
            
			break;
		}
	case HEARTBEAT_MSG:
		{
			break;
		}
	case SERVICE_MSG:
		{
			DMMessage server_msg;
            server_msg = client_msg;
            
            ProxyService::instance()->dispatch(server_msg);
            
			break;
		}
	}

	return 0;
}
	
bool ProxyServiceHandle::recv_client_data(DMMessage &msg)
{
	char head[HEAD_CHAR_LEN] = {0};
	if (peer().recv(head,HEAD_CHAR_LEN) < 1)
    {
        user_disconnect(peer().get_handle());
        return false;
    }   
	
	DMMessageParser parser;
	DMMessageHead head_info;
	//parse head
	head_info = parser.parse(head);

    //some message maybe have no message body
    do
    {
    	if ( head_info.length <= 0 )
    	{
    		break;
    	}

    	//recive body
    	msg.require_body_size(head_info.length);
    	memset(msg.body,0,head_info.length);
    	peer().recv(msg.body,head_info.length);
        
    }while(false);

	msg.head = head_info;

	return true;
}

void ProxyServiceHandle::user_connect(ACE_HANDLE fd, short uid)
{
    ProxySessionMgr::instance()->add_session(fd, uid, new ProxySession(this));//fd作为sessionid
}

void ProxyServiceHandle::user_disconnect(ACE_HANDLE fd)
{
    ProxySessionMgr::instance()->del_session(fd);//fd作为sessionid
    handle_close();
}


void ProxyServiceHandle::user_activate(DMMessage &msg)
{
    ProxySessionMgr::instance()->activate_session(msg.head.user_id);
}

int ProxyServiceHandle::open(void *acceptor_or_connector /*= 0*/)
{
	ACE_Reactor *pReactor = Reactor_Pool::instance()->pull();
	if ( -1 == get_handle() || nullptr == pReactor)
	{
		return -1;
	}

	if ( -1 == pReactor->register_handler(this,ACE_Event_Handler::READ_MASK /*| ACE_Event_Handler::WRITE_MASK*/))
	{
		ACE_DEBUG((LM_INFO,"register_handler failure,all reactor is full!\n"));
		return -1;
	}

	return 0;
}

void ProxyServiceHandle::maintain_service(short cmd)
{
    switch (cmd)
	{
	case STOP_SERVER:
		{
			ACE_Reactor::instance()->end_reactor_event_loop();
		}
		//停服
	default:
		break;
	}
}

