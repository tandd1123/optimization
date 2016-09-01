#pragma once
#include "DMRouter.h"
#include "DMServiceMap.h"
#include "ProxySessionMgr.h"
#include "DMMessageParser.h"
#include <ace/Log_Msg.h>

class ProxyRouter:public DMRouter
{
public:
	//添加路由消息到客户端的能力,服务器间路由基类实现
	virtual void route(DMMessage& message, std::string exchange) override
	{
	    std::map<std::string, int> service_map = DMServiceMap::instance()->service_map;
        //send to app
        if (service_map["appclient"] == message.head.to)
        {
            ACE_HANDLE app_fd = ProxySessionMgr::instance()->find_fd(message.head.user_id);
            ACE_SOCK_Stream peer(app_fd);
            DMMessageParser parser;
            //pack msg
            char *buf = new char[HEAD_CHAR_LEN + message.head.length];
            parser.pack(message,buf);
            peer.send_n(buf,HEAD_CHAR_LEN + message.head.length);
            
            delete[] buf;
            return;
        }      
        
		DMRouter::route(message, exchange);
	}

protected:
private:
};
