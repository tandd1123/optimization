//=============================================================================
/* 
*  File: DMMessageRouter.h
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

//消息路由器。将服务器消息路由到消息服务器
//对于普通服务，直接使用就可。 对于proxyServer，需要重载，添加路由到客户端的能力。

#define FANOUT "fanout"
#define DIRECT "direct"
#define TOPIC "topic"

class DMMessageRouter
{
public:
    virtual void send(DMMessage& message, string exchange = "direct");

    virtual void publish(DMMessage& message);
        
protected:
    
	virtual void route(DMMessage& message, string exchange);
            
private:

    DM_BOOL route_assign(DMMessage& message, string exchange);

    void route_distribute(DMMessage& message, DM_UINT service_id, string exchange);

};

