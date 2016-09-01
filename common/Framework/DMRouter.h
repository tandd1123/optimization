#pragma once
#include "DMMessage.h"
#include "DMServiceMap.h"
#include "DMRedis.h"
#include "DMMySQL.h"

//消息路由器。将服务器消息路由到消息服务器
//对于普通服务，直接使用就可。 对于proxyServer，需要重载，添加路由到客户端的能力。

#define FANOUT "fanout"
#define DIRECT "direct"
#define TOPIC "topic"

class DMRouter
{
public:
    virtual void send(DMMessage& message, std::string exchange = "direct");

    virtual void publish(DMMessage& message);
        
protected:
    
	virtual void route(DMMessage& message, std::string exchange);
            
private:

    bool route_assign(DMMessage& message, std::string exchange);

    void route_distribute(DMMessage& message, int service_id, std::string exchange);

private:
    DMRedis _redis;
    DMMySQL _mysql;
};

