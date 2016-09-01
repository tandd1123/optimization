#include "DMMessageRouter.h"

void DMMessageRouter::send(DMMessage& message, string exchange)
{
    //有路由表数据需要维护该用户路由表信息,需要维护redis内存数据和mysql数据
    if (0 != message.head.cluster_id && 0 != message.head.node_id)
    {
        string domain = _redis.pack_domain(message.head.user_id, "cluster_id");
        _redis.write_redis_hash("TBL_ROUTE" , domain, message.head.cluster_id);
        
        domain = _redis.pack_domain(message.head.user_id, "node_id");
        _redis.write_redis_hash("TBL_ROUTE" , domain, message.head.node_id);
    }

    route(message, exchange);
}

void DMMessageRouter::publish(DMMessage& message)
{
    route(message, FANOUT);
}

void DMMessageRouter::route(DMMessage& message, string exchange)
{
    //优先依据集群节点数据指定路由
    if (route_assign(message, exchange))
    {
        return;
    }

    map<DM_INT32, MsgRange> message_map = DMServiceMap::instance()->message_map;
    map<DM_INT32, MsgRange>::iterator it = message_map.begin();

    DM_INT32 svr_id = 0;
    for (; it != message_map.end(); ++it)
    {
        MsgRange range = it->second;
        if (message.head.msg_cmd > range.msg_start &&
                message.head.msg_cmd < range.msg_end)
        {       
            svr_id = it->first;
            break;
        }
    }

    if (0 != svr_id)
    {   
        //将message推送到rabbitmq-server，选择消息最少的队列
        route_distribute(message, svr_id, exchange);
    }
}

DM_BOOL DMMessageRouter::route_assign(DMMessage& message, string exchange)
{
    DMMessageParser parser;
    //pack msg
    DM_CHAR *buf = DM_NEW() DM_CHAR[HEAD_DM_CHAR_LEN + message.head.length];
    parser.pack(message,buf);
    
    string domain = _redis.pack_domain(message.head.user_id, "cluster_id");
    string cluster = _redis.read_redis_hash("TBL_ROUTE",domain);
    
    domain = _redis.pack_domain(message.head.user_id, "node_id");
    string node = _redis.read_redis_hash("TBL_ROUTE",domain);

    if (cluster == "nil" || node == "nil")
    {
        //查询mysql
    }

    //指定发送，节点处理方式待重新考虑
    DMMessageQueue::getInstance()->publish(exchange, cluster, buf, HEAD_DM_CHAR_LEN + message.head.length);
    return TRUE;
}

void DMMessageRouter::route_distribute(DMMessage& message, DM_INT32 service_id, string exchange)
{
    DMMessageParser parser;
    //pack msg
    DM_CHAR *buf = DM_NEW() DM_CHAR[HEAD_DM_CHAR_LEN + message.head.length];
    parser.pack(message,buf);
    
    //消息直接负载映射无指定cluster、node场景
    map<DM_INT32, vector<string>> queue_map = DMServiceMap::instance()->queue_map;
    vector<string> queue = queue_map[service_id];
    vector<string>::iterator it = queue.begin();
    //第一个队列作为初始化值
    string queueName = *it;
    DM_INT32 msgCount = DMMessageQueue::getInstance()->getQueueMsgCount(queueName);

    for (; it != queue.end(); ++it)
    {
        DM_INT32 size = DMMessageQueue::getInstance()->getQueueMsgCount(queueName);
        if (msgCount > size)
        {
            queueName = *it;
            msgCount = size;
        }
    }
    
    DMMessageQueue::getInstance()->publish(exchange, queueName, buf, HEAD_DM_CHAR_LEN + message.head.length);

    DM_DELETE()[] buf;
}

