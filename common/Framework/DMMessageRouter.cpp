#include "DMMessageRouter.h"
#include "DMSessionManager.h"

void DMMessageRouter::publish(DMMessage& message)
{
    send(message, FANOUT);
}

DM_BOOL DMMessageRouter::receive(ACE_HANDLE fd, DMMessage& message)
{
    DM_CHAR head[HEAD_CHAR_LEN] = {0};
    ACE_SOCK_Stream stream(fd);
	if (stream.recv(head,HEAD_CHAR_LEN) < 1)
    {
        DM_LOG(DM_INFO,"revice head error!");
        user_disconnect(fd);
        return false;
    }   
        
	DMMessageParser parser;
	DMMessageHead head_info;
	//parse head
	head_info = parser.parse(head);

    DM_UINT32 max_size = DMJsonCfg::instance()->GetItemInt("service_config", "message_max_size");
	if ( head_info.length <= 0 || head_info.length > max_size)
	{
	    DM_LOG(DM_INFO,"parse head error!");
		return false;;
	}
    
	user_connect(fd, head_info.msg_uid);

	//recive body
	message.require_body_size(head_info.length);
	memset(message.body,0,head_info.length);
	stream.recv(message.body,head_info.length);
        
	message.head = head_info;

	return true;
}

DM_BOOL DMMessageRouter::receive(DMMessage& message, const AMQP::Message& mq_message)
{
	DMMessageParser parser;
	//parse head
	parser.parse(message, mq_message);
    
    return true;
}

void DMMessageRouter::send(DMMessage& message, string exchange)
{
    map<DM_INT32, MsgRange> message_map = DMServiceMap::instance()->message_map;
    map<DM_INT32, MsgRange>::iterator it = message_map.begin();

    DM_INT32 svr_id = 0;
    for (; it != message_map.end(); ++it)
    {
        MsgRange range = it->second;
        //start =
        if (message.head.msg_cmd >= range.msg_start &&
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

void DMMessageRouter::send(ACE_HANDLE fd, DMMessage& msg)
{
    ACE_SOCK_Stream stream(fd);
    DM_CHAR* buf;
    buf = new DM_CHAR[sizeof(DMMessageHead) + msg.head.length];
    
    DMMessageParser parser;
    parser.pack(msg, buf);
    
    stream.send_n(buf, sizeof(DMMessageHead) + msg.head.length);
    
    delete[] buf;
}

void DMMessageRouter::route_distribute(DMMessage& message, DM_INT32 service_id, string exchange)
{
    DMMessageParser parser;
    //pack msg
    DM_CHAR *buf = new DM_CHAR[HEAD_CHAR_LEN + message.head.length];
    parser.pack(message,buf);
    
    //消息直接负载映射无指定cluster、node场景
    map<DM_INT32, vector<string>> queue_map = DMServiceMap::instance()->queue_map;
    vector<string> queue = queue_map[service_id];
    vector<string>::iterator it = queue.begin();
    //第一个队列作为初始化值
    string queueName = *it;
    DM_INT32 msgCount = DMMessageQueue::instance()->getQueueMsgCount(queueName);

    for (; it != queue.end(); ++it)
    {
        DM_INT32 size = DMMessageQueue::instance()->getQueueMsgCount(queueName);
        if (msgCount > size)
        {
            queueName = *it;
            msgCount = size;
        }
    }
    
    DMMessageQueue::instance()->publish(exchange, queueName, buf, HEAD_CHAR_LEN + message.head.length);

    delete[] buf;
}

void DMMessageRouter::user_connect(ACE_HANDLE fd, short uid)
{
    DMSessionMgr::instance()->add_session(uid, fd);//fd作为sessionid
}

void DMMessageRouter::user_disconnect(ACE_HANDLE fd)
{
    DMSessionMgr::instance()->del_session(fd);//fd作为sessionid
}

